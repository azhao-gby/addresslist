#include "addresslist.h"
//目录
void menu()
{
    printf("———————————欢迎使用通讯录———————————\n");
    printf("———1.添加用户信息 2.显示用户信息————\n");
    printf("———3.搜索用户信息 4.删除用户信息————\n");
    printf("———5.修改用户信息 6.退出通讯录——————\n");
    printf("————————————————————————————————————\n");
}
//创建一个新的链表
addresslist *addresslistCreate()
{
    addresslist *head = (addresslist *)malloc(sizeof(addresslist));
    head->next = NULL;
    return head;
}
//判断是否为空
bool addresslistIsEmpty(addresslist *head)
{
    return head->next == NULL ? 1 : 0;
}
//单链表的整表删除
void addresslistClear(addresslist *head)
{
    if (addresslistIsEmpty(head))
    {
        printf("通讯录为空！\n");
        return;
    }
    addresslist *p, *q;
    p = head->next;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
    head->next = NULL;
    return;
}
//存储文件
void WriteList(addresslist *head)
{
    FILE *fp = fopen("./list.txt", "w");
    if (fp == NULL)
    {
        printf("通讯录为空!\n");
        return;
    }
    addresslist *p = head->next;
    while (p != NULL)
    {
        fwrite(p, sizeof(list), 1, fp);
        p = p->next;
    }
    fclose(fp);
}
// 读取文件放入链表
void ReadList(addresslist *head)
{
    addresslist *p = head;
    head->next = NULL;
    FILE *fp = fopen("./list.txt", "r");
    if (fp == NULL)
    {
        printf("通讯录为空，请输入信息\n");
        return;
    }
    while (1)
    {
        addresslist *tmp = (addresslist *)malloc(sizeof(addresslist));
        tmp->next = NULL;
        fread(tmp, sizeof(list), 1, fp);
        if (feof(fp) != 0) //要在fread之后判断
        {
            break;
        }
        if (1 == addresslistIsEmpty(head))
        {
            tmp->next = head->next;
            head->next = tmp;
        }
        else
        {
            while (p->next != NULL && strcmp(p->next->data.name, tmp->data.name) < 0)
            {
                p = p->next;
            }
            tmp->next = p->next;
            p->next = tmp;
        }
    }
    fclose(fp);
}
// 添加用户+排序
void addresslistInsertSort(addresslist *head)
{
    char flag = 'y';
    while (flag == 'y')
    {
        addresslist *tmp = (addresslist *)malloc(sizeof(addresslist));
        printf("请输入id:\n");
        scanf("%s", tmp->data.id);
        printf("请输入姓名:\n");
        scanf("%s", tmp->data.name);
        while (head->next != NULL && strcmp(head->next->data.name, tmp->data.name) < 0)
        {
            head = head->next;
        }
        printf("请输入年龄:\n");
        scanf("%s", tmp->data.age);
        printf("请输入电话:\n");
        scanf("%s", tmp->data.tel);
        tmp->next = head->next;
        head->next = tmp;
        getchar();
        printf("是否继续输入【y/n】:");
        printf("\n");
        scanf("%c", &flag);
    }
}
//遍历
int addresslistprint(addresslist *head)
{
    if (addresslistIsEmpty(head))
    {
        printf("通讯录为空!\n");
        return -1;
    }
    addresslist *p = head->next;
    printf("id\t\t姓名\t\t年龄\t\t电话\n");
    printf("—————————————————————————————————————————————————————\n");
    while (p != NULL)
    {
        printf("%s\t\t%s\t\t%s\t\t%s\n", p->data.id, p->data.name, p->data.age, p->data.tel);
        p = p->next;
    }
    return 0;
}
//搜索用户，按照姓名
int addresslistSearchName(addresslist *head)
{
    addresslist *p = head;
    char n[NAME_MAX];
    if (addresslistIsEmpty(head))
    {
        printf("通讯录为空!\n");
        return (int)-1;
    }
    printf("请输入要搜索的姓名：\n");
    scanf("%s", n);
    while (p != NULL)
    {
        if (strcmp(n, p->data.name) == 0)
        {
            printf("id\t\t姓名\t\t年龄\t\t电话\n");
            printf("—————————————————————————————————————————————————————\n");
            printf("%s\t\t%s\t\t%s\t\t%s\n", p->data.id, p->data.name, p->data.age, p->data.tel);
            printf("\n");
            return -1;
        }
        p = p->next;
    }
    printf("查无此人\n");
}
//搜索用户，按照id
int addresslistSearchId(addresslist *head)
{
    addresslist *p = head;
    char I[ID_MAX];
    if (addresslistIsEmpty(head))
    {
        printf("通讯录为空!\n");
        return (int)-1;
    }
    printf("请输入要搜索的id：\n");
    scanf("%s", I);
    while (p != NULL)
    {
        if (strcmp(I, p->data.id) == 0)
        {
            printf("id\t\t姓名\t\t年龄\t\t电话\n");
            printf("—————————————————————————————————————————————————————\n");
            printf("%s\t\t%s\t\t%s\t\t%s\n", p->data.id, p->data.name, p->data.age, p->data.tel);
            printf("\n");
            return -1;
        }
        p = p->next;
    }
    printf("查无此人\n");
}
//合并搜索
int addersslistsearch(addresslist *head)
{
    if (addresslistIsEmpty(head))
    {
        printf("通讯录为空!\n");
        return (int)-1;
    }
    int choice;
    char flag = 'y';
    while (flag == 'y')
    {
        printf("——————————————搜索用户———————————————\n");
        printf("——————1.id————————2.用户名———————————\n");
        printf("请输入你的选择:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addresslistSearchId(head);
            break;
        case 2:
            addresslistSearchName(head);
            break;
        default:
            printf("选择错误！\n");
            break;
        }
        getchar();
        printf("是否继续搜索【y/n】:");
        printf("\n");
        scanf("%c", &flag);
    }
}
//删除用户
int addresslistDelete(addresslist *head)
{
    char n[NAME_MAX];
    if (addresslistIsEmpty(head))
    {
        printf("通讯录为空!\n");
        return -1;
    }
    addresslist *p = head;
    addresslist *q;
    printf("请输入要删除的姓名：\n");
    scanf("%s", n);
    int flag = 0;
    while (p->next != NULL)
    {
        if (strcmp(p->next->data.name, n) == 0)
        {
            q = p->next;
            p->next = q->next;
            free(q);
            q = NULL;
            flag = 1;
            printf("删除成功\n");
            return 0;
        }
        p = p->next;
    }
    if (flag == 1)
    {
        printf("没有此人，删除失败\n");
    }
}
//修改用户
int addresslistUpdate(addresslist *head)
{
    char n[NAME_MAX];
    char i[ID_MAX];
    char a[AGE_MAX];
    char t[TEL_MAX];
    if (addresslistIsEmpty(head))
    {
        // printf("通讯录为空\n");
        return -1;
    }
    printf("请输入要修改的姓名：\n");
    scanf("%s", n);
    addresslist *p = head;
    int flag = 0;
    while (p->next != NULL)
    {
        p = p->next;
        if (strcmp(p->data.name, n) == 0)
        {
            printf("请输入id:\n");
            scanf("%s", i);
            strcpy(p->data.id, i);
            printf("请输入姓名:\n");
            scanf("%s", n);
            strcpy(p->data.name, n);
            printf("请输入年龄:\n");
            scanf("%s", a);
            strcpy(p->data.age, a);
            printf("请输入电话:\n");
            scanf("%s", t);
            strcpy(p->data.tel, t);
            printf("修改成功\n");
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("查无此人,修改失败\n");
        return -1;
    }
}