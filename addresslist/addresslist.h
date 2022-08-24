#ifndef _ADDRESSLIST_H_
#define _ADDRESSLIST_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#define ID_MAX 1024
#define NAME_MAX 1024
#define AGE_MAX 1024
#define TEL_MAX 1024
typedef struct
{
    char id[ID_MAX];
    char name[NAME_MAX];
    char age[AGE_MAX];
    char tel[TEL_MAX];
} list;
typedef struct node
{
    list data;
    struct node *next;
} addresslist;
//目录
void menu();
//创建一个新的链表
addresslist *addresslistCreate();
//判断是否为空
bool addresslistIsEmpty(addresslist *head);
// 添加用户+排序
void addresslistInsertSort(addresslist *head);
//遍历
int addresslistprint(addresslist *head);
//搜索用户，按照姓名
int addresslistSearchName(addresslist *head);
//搜索用户，按照id
int addresslistSearchId(addresslist *head);
//合并搜索
int addersslistsearch(addresslist *head);
//删除用户
int addresslistDelete(addresslist *head);
//修改用户
int addresslistUpdate(addresslist *head);
// 读取文件放入链表
void ReadList(addresslist *head);
//存储文件
void WriteList(addresslist *head);
//单链表的整表删除
void addresslistClear(addresslist *head);
#endif