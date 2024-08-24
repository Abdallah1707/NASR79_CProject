#include "SDB.h"

void SDB_APP()
{
    uint8 op;
    while(1)
    {
        printf("1. To add entry, enter 1\n"
        "2. To get used size in database, enter 2\n"
        "3. To read student data, enter 3\n"
        "4. To get the list of all student IDs, enter 4\n"
        "5. To check is ID is existed, enter 5\n"
        "6. To delete student data, enter 6\n"
        "7. To check is database is full, enter 7\n"
        "8. To exit enter 0\n");

        scanf("%d", &op);

        if(op == 0) break;
        
        if(op < 0 || op > 7)
        {
            printf("invalid choice\n");
            continue;
        }

        SDB_action(op);
    }
}
void SDB_action(uint8 choice)
{
    int32 id;
    Bool flag;

    switch (choice)
    {
    case 1:
        flag = SDB_AddEntry();

        if(flag) printf("entry added\n");
        else printf("error\n");

        break;

    case 2:
        printf("number of students in database is %d\n",SDB_GetUsedSize());
        break;

    case 3:
        puts("enter student ID");
        scanf("%d", &id);

        flag = SDB_ReadEntry(id);

        if(!flag) printf("id not found\n");
        

        break;

    case 4:
        SDB_GetList();

        break;

    case 5:
        puts("enter student ID");
        scanf("%d", &id);

        if(SDB_IsIdExist(id))
            printf("ID exists\n");

        else
            printf("ID does not exist\n");

        break;

    case 6:
        puts("enter student ID");

        scanf("%d", &id);
        SDB_DeletEntry(id);

        break;

    case 7:

        if(SDB_IsFull())
        printf("Database is full\n");

        else 
        printf("Database is not full\n");

        break;
    
    default:
        break;
    }
}