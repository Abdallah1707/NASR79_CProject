#include "SDB.h"

student studentDataBase[10];

Bool SDB_IsFull()
{
    for(int i = 0; i < 10 ; i++)
    {
        if(studentDataBase[i].Student_ID == 0)
            return FALSE;
    }
    return TRUE;
}
uint8 SDB_GetUsedSize()
{
    uint8 counter = 0;
    for(int i = 0; i < 10 ; i++)
    {
        if(studentDataBase[i].Student_ID != 0)
           counter++; 
    }
    return counter;
}
Bool SDB_AddEntry()
{
    uint32 studentData[8];
    int8 index = -1;

    printf("ID: ");
    scanf("%d", &studentData[0]);
    printf("\nYear: ");
    scanf("%d", &studentData[1]);
    printf("\nCourse1_ID: ");
    scanf("%d", &studentData[2]);
    printf("\nCourse1_grade: ");
    scanf("%d", &studentData[3]);
    printf("\nCourse2_ID: ");
    scanf("%d", &studentData[4]);
    printf("\nCourse2_grade: ");
    scanf("%d", &studentData[5]);
    printf("\nCourse3_ID: ");
    scanf("%d", &studentData[6]);
    printf("\nCourse3_grade: ");
    scanf("%d", &studentData[7]);
    printf("\n");

    for(int i = 0 ; i < 8 ; i++)
    {
        if(studentData[i] <= 0 )
            return FALSE;
    }
    
    for(int i = 0 ; i < 10 ; i++)
    {
        if(studentDataBase[i].Student_ID == 0)
            index = i;
        
    }
    if(index < 0 )
    {
        // printf("Database is full\n");
        return FALSE;
    }

    studentDataBase[index] = (student) { .Student_ID    = studentData[0],
                                         .Student_year  = studentData[1],
                                         .Course1_ID    = studentData[2],
                                         .Course1_grade = studentData[3],
                                         .Course2_ID    = studentData[4],
                                         .Course2_grade = studentData[5],
                                         .Course3_ID    = studentData[6],
                                         .Course3_grade = studentData[7]};
                            
    return TRUE;
}
void SDB_DeletEntry(uint32 id)
{
    int8 index = getIndex(id);
    if(index < 0) return;

    studentDataBase[index] = (student) { .Student_ID    = 0, .Student_year  = 0,
                                         .Course1_ID    = 0, .Course1_grade = 0,
                                         .Course2_ID    = 0, .Course2_grade = 0,
                                         .Course3_ID    = 0, .Course3_grade = 0};

    
}
Bool SDB_ReadEntry(uint32 id)
{
    int8 index = getIndex(id);
    
    if(index < 0)return FALSE;

    printf("id : %d"
    "\nyear: %d"
    "\ncourse1 id: %d"
    "\ncourse1 grade: %d"
    "\ncourse2 id: %d"
    "\ncourse2 grade: %d"
    "\ncourse3 id: %d"
    "\ncourse3 grade: %d\n",
    studentDataBase[index].Student_ID, studentDataBase[index].Student_year,
    studentDataBase[index].Course1_ID, studentDataBase[index].Course1_grade,
    studentDataBase[index].Course2_ID, studentDataBase[index].Course2_grade,
    studentDataBase[index].Course3_ID, studentDataBase[index].Course3_grade);

    return TRUE;
}
void SDB_GetList()
{
    for(uint8 i = 0 ; i < 10 ; i++)
    {
        if(studentDataBase[i].Student_ID != 0)
        {
            printf("%d\n", studentDataBase[i].Student_ID);     
        }
    }
}
Bool SDB_IsIdExist(uint32 id)
{
    if(getIndex(id) < 0)return FALSE;
    else return TRUE;
}
int8 getIndex(uint32 id)
{

    for(int8 i = 0; i < 10 ; i++)
    {
        if(studentDataBase[i].Student_ID == id)
            return i;
    }
    
    return -1;
}


