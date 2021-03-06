
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

typedef int Status;   /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType; /* ElemType类型根据实际情况而定，这里假设为int */

Status visit(ElemType c)
{
    printf("%d ", c);
    return OK;
}

typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;

typedef struct Node *LinkList;

/* 初始化顺序线性表 */
Status InitList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(Node)); /* 产生头结点,并使L指向此头结点 */
    if (!(*L))                           /* 存储分配失败 */
    {
        return ERROR;
    }
    (*L)->next = NULL; /* 指针域为空 */
    return OK;
}
/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Status ListEmpty(LinkList L)
{
    if (L->next)
    {
        return FALSE;
    }
    return TRUE;
}
/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status ClearList(LinkList *L)
{
    LinkList p, q;
    p = (*L)->next;
    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return OK;
}
/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(LinkList L)
{
    if (ListEmpty(L))
    {
        return 0;
    }

    int i = 0;
    LinkList p = L->next; /* p指向第一个结点 */
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值 */
Status GetElem(LinkList L, int i, ElemType *e)
{
    if (ListEmpty(L))
    {
        return ERROR;
    }

    int j = 1;
    LinkList p = L->next; /* 声明一结点p */
    while (p && j < i)    /* p不为空或者计数器j还没有等于i时，循环继续 */
    {
        p = p->next; /* 让p指向下一个结点 */
        ++j;
    }
    if (!p || j > i) /*  第i个元素不存在 */
    {
        return ERROR;
    }
    *e = p->data; /*  取第i个元素的数据 */
    return OK;
}
/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为-1 */

int LocateElem(LinkList L, ElemType e)
{
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
Status ListInsert(LinkList *L, int i, ElemType e)
{
    int j = 1;
    LinkList p, s;
    p = *L;
    while (p && j < i) /* 寻找第i个结点 */
    {
        j++;
        p = p->next;
    }
    if (!p && j > i)
    {
        return ERROR; /* 第i个元素不存在 */
    }
    s = (LinkList)malloc(sizeof(Node)); /*  生成新结点(C语言标准函数) */
    s->data = e;
    s->next = p->next; /* 将p的后继结点赋值给s的后继  */
    p->next = s;       /* 将s赋值给p的后继 */
    return OK;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(LinkList *L, int i, ElemType *e)
{
    if (i > ListLength(*L))
    {
        return ERROR;
    }

    int j = 1;
    LinkList p, q;
    p = *L;
    while (p && j < i) /* 寻找第i个结点 */
    {
        j++;
        p = p->next;
    }
    if (!(p->next) && j > i)
    {
        return ERROR; /* 第i个元素不存在 */
    }
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}
/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(LinkList L)
{
    LinkList p = L->next;
    while (p)
    {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}
/*  随机产生n个元素的值，建立带表头结点的单链线性表L（头插法） */
Status CreateListHead(LinkList *L, int n)
{
    LinkList p;
    int i;
    srand(time(0)); /* 初始化随机数种子 */
    InitList(L);
    for (i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(Node)); /*  生成新结点 */
        p->data = rand() % 100 + 1;         /*  随机生成100以内的数字 */
        p->next = (*L)->next;
        (*L)->next = p; /*  插入到表头 */
    }
    return OK;
}
/*  随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法） */
Status CreateListTail(LinkList *L, int n)
{
    LinkList p, r;
    int i;
    srand(time(0)); /* 初始化随机数种子 */
    InitList(L);
    r = *L; /* r为指向尾部的结点 */
    for (i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(Node)); /*  生成新结点 */
        p->data = rand() % 100 + 1;         /*  随机生成100以内的数字 */
        r->next = p;                        /* 将表尾终端结点的指针指向新结点 */
        r = p;
    }
    r->next = NULL; /* 表示当前链表结束 */
    return OK;
}
//在后面插入node
Status InsertNode(Node *head, Node *newNode)
{
    if (head == NULL || newNode == NULL)
    {
        return ERROR;
    }
    newNode->next = head->next;
    head->next = newNode;
    return OK;
}
//
Status TraverseNode(Node *head)
{
    if (head == NULL)
    {
        return ERROR;
    }
    Node *tmp = head->next;
    while (tmp)
    {
        visit(tmp->data);
        tmp = tmp->next;
    }
    return OK;
}
//链表反转
LinkList *ReverseLink(LinkList *L)
{
    //使用头插法，每取出一个结果，插入到第二个表的第一个
    if (L == NULL)
    {
        return NULL;
    }
    Node *p = (*L)->next; //取出第一个
    (*L)->next = NULL;    //断开链表
    Node *tmp = NULL;     //临时变量
    while (p)
    {
        tmp = p->next;
        ListInsert(L, 1, p->data); //插入到旧表的第一个
        p = tmp;
    }
    return L;
}
//判断该链表有没有环
Status CheckCircle(LinkList *L)
{
    if (L == NULL)
    {
        return FALSE;
    }
    Node *slow;
    Node *fast;
    slow = (*L)->next;
    fast = slow->next;
    while (slow != fast)
    {
        slow = slow->next;
        if (fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
        }
        else
        {
            return FALSE;
        }
    }
    return TRUE;
}

//判断中间节点.其实有可能有两个，用数组更好
Node *GetCenterNode(LinkList *L)
{
    if (L == NULL)
    {
        return NULL;
    }
    Node *slow;
    Node *fast;
    slow = (*L)->next;
    fast = slow->next;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    if (fast->next == NULL)
    {
        return slow;
    }
    if (fast->next->next == NULL)
    {
        return slow->next;
    }
    return NULL;
}

//判断中间节点，设定两个指针，第一个指针每走两步，后面的走一步。如果后面的为空，那么前面的是中间，如果办能走一步。那么前面的走一步为中间节点
//求倒数第n个节点，还是一样，用两个指针，汉第一个走了n步时如果后面还有节点，这时第二个指针出场。直到第一个后面没数据为止
//有序链表合并，这个就是相互比再相互插入就行
int main()
{
    LinkList L;
    ElemType e;
    Status i;
    int j, k;

    printf("%d", j);

    i = InitList(&L);
    printf("初始化L后：ListLength(L)=%d\n", ListLength(L));
    for (j = 1; j <= 5; j++)
        i = ListInsert(&L, 1, j);
    printf("在L的表头依次插入1～5后：L.data=");
    ListTraverse(L);

    printf("ListLength(L)=%d \n", ListLength(L));
    i = ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n", i);

    i = ClearList(&L);
    printf("清空L后：ListLength(L)=%d\n", ListLength(L));
    i = ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n", i);

    for (j = 1; j <= 10; j++)
        ListInsert(&L, j, j);
    printf("在L的表尾依次插入1～10后：L.data=");
    ListTraverse(L);

    printf("ListLength(L)=%d \n", ListLength(L));

    ListInsert(&L, 1, 100);
    printf("在L的表头插入100后：L.data=");
    ListTraverse(L);
    printf("ListLength(L)=%d \n", ListLength(L));

    GetElem(L, 5, &e);
    printf("第5个元素的值为：%d\n", e);

    for (j = 3; j <= 4; j++)
    {
        k = LocateElem(L, j);
        if (k)
            printf("第%d个元素的值为%d\n", k, j);
        else
            printf("没有值为%d的元素\n", j);
    }

    k = ListLength(L); /* k为表长 */
    for (j = k + 1; j >= k; j--)
    {
        i = ListDelete(&L, j, &e); /* 删除第j个数据 */
        if (i == ERROR)
            printf("删除第%d个数据失败\n", j);
        else
            printf("删除第%d个的元素值为：%d\n", j, e);
    }

    printf("依次输出L的元素：");
    ListTraverse(L);

    j = 5;
    ListDelete(&L, j, &e); /* 删除第5个数据 */
    printf("删除第%d个的元素值为：%d\n", j, e);

    printf("依次输出L的元素：");
    ListTraverse(L);

    i = ClearList(&L);
    printf("\n清空L后：ListLength(L)=%d\n", ListLength(L));
    CreateListHead(&L, 20);
    printf("整体创建L的元素(头插法)：");
    ListTraverse(L);

    i = ClearList(&L);
    printf("\n删除L后：ListLength(L)=%d\n", ListLength(L));
    CreateListTail(&L, 5);
    printf("整体创建L的元素(尾插法)：\n");
    ListTraverse(L);
    LinkList *newNode = ReverseLink(&L);
    ListTraverse(L);
    printf("这个表有没有环%d \n", CheckCircle(&L));
    printf("下面加一个环 \n");
    // Node* tmp = L->next;
    // while (tmp->next != NULL)
    // {
    //     tmp = tmp->next;
    // }
    // tmp->next = L->next->next;

    //  printf("这个表有没有环%d \n",CheckCircle(&L));
    Node *center = GetCenterNode(&L);
    printf("中间是%d \n", center->data);
    ListInsert(&L, 1, 100);
    ListTraverse(L);
    printf("中间是%d \n", GetCenterNode(&L)->data);
    return 0;
}