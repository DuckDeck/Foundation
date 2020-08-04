#include "stdio.h"    

#include "stdlib.h"   
#include <sys/uio.h>
#include "math.h"  
#include "time.h"
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */

Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}

typedef struct Node
{
    ElemType data;
    struct Node *next;
    struct Node *prev
}Node;

typedef struct Node *LinkList;

/* 初始化顺序线性表 */
Status InitList(LinkList *L){
    *L = (LinkList)malloc(sizeof(Node)); /* 产生头结点,并使L指向此头结点 */
    if (!(*L))  /* 存储分配失败 */
    {
       return ERROR;
    }
    (*L)->next = NULL;/* 指针域为空 */
    (*L)->prev = NULL;/* 指针域为空 */
    return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Status ListEmpty(LinkList L){
    if (L->next)
    {
        return FALSE;
    }
    return TRUE;
}

/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status ClearList(LinkList *L){
    LinkList p,q;
    p = (*L)->next;
    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    } 
    (*L)->next = NULL;
    (*L)->prev = NULL;
    return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(LinkList L){
    if (ListEmpty(L))
    {
       return 0;
    }
    
    int i = 0;
    LinkList p = L->next; /* p指向第一个结点 */
    while (p)
    {
        i++;
        p=p->next;
    }
    return i;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值 */
Status GetElem(LinkList L,int i,ElemType *e){
    if (ListEmpty(L))
    {
        return ERROR;
    }
    
    int j = 1;
    LinkList p = L->next; /* 声明一结点p */
    while (p && j<i)  /* p不为空或者计数器j还没有等于i时，循环继续 */
    {
       p=p->next; /* 让p指向下一个结点 */
       ++j;
    }
    if (!p || j>i) /*  第i个元素不存在 */
    {
        return ERROR; 
    }
    *e = p->data; /*  取第i个元素的数据 */
    return OK;
}
/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为-1 */
int LocateElem(LinkList L,ElemType e){
     if (ListEmpty(L))
    {
        return -1;
    }
    int i = 0;
    LinkList p = L->next;
    while (p)
    {
        i++;
        if (e == p->data)
        {
           return i;
        }
        p = p->next;
    }
    return -1;
}

/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
Status ListInsert(LinkList *L,int i,ElemType e){
    int j = 1;
    LinkList p,s;
    p = *L;
    while (p && j < i)   /* 寻找第i个结点 */
    {
        j++;
        p = p->next;
    }
    if (!p && j > i)
    {
        return ERROR;  /* 第i个元素不存在 */
    }
    s = (LinkList)malloc(sizeof(Node));  /*  生成新结点(C语言标准函数) */
    s->data = e;
    s->next = p->next;   /* 将p的后继结点赋值给s的后继  */
    p->next->prev = s;  /* 将p的后继结点的前结点赋值给s  */
    s->prev = p;        /* 将s前结点是p */
    p->next = s;         /* 将s赋值给p的后继 */
    return OK;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(LinkList *L,int i,ElemType *e){
    if (i>ListLength(*L))
    {
        return ERROR;
    }
    int j = 1;
    LinkList p,q;
    p = *L;
    while (p && j < i)   /* 寻找第i个结点 */
    {
        j++;
        p = p->next;
    }
    if (!(p->next) && j > i)
    {
        return ERROR;  /* 第i个元素不存在 */
    }
    q = p->next;
    q->next->prev = p;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(LinkList L){
    LinkList p = L->next;
    while (p)
    {
        visit(p->data);
        p=p->next;
    }
    printf("\n");
    return OK;    
}

