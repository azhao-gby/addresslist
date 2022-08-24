#include "addresslist.h"
int main()
{

    addresslist *head = addresslistCreate();
    int i;
    int choice;
    char flag = 'y';
    while (flag == 'y')
    {
        menu();
        printf("请输入你的选择>\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            ReadList(head);
            addresslistInsertSort(head);
            WriteList(head);
            break;
        case 2:
            addresslistClear(head);
            ReadList(head);
            addresslistprint(head);
            break;
        case 3:
            addresslistClear(head);
            ReadList(head);
            addersslistsearch(head);
            break;
        case 4:
            addresslistClear(head);
            ReadList(head);
            addresslistDelete(head);
            WriteList(head);
            break;
        case 5:
            addresslistClear(head);
            ReadList(head);
            addresslistUpdate(head);
            WriteList(head);
            break;
        case 6:
            printf("———————退出通讯录，欢迎下次使用—————\n");
            return 0;
            break;
        default:
            printf("选择错误！\n");
            break;
        }
        getchar();
        printf("是否回到通讯录【y/n】:");
        printf("\n");
        scanf("%c", &flag);
    }
}