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


typedef struct StackNode
{
    ElemType data;
    struct StackNode *next;
} StackNode, *LinkStackPtr;

typedef struct LinkStack{
    LinkStackPtr top;
    int count;
}LinkStack;


Status visit(ElemType c)
{
        printf("%d ",c);
        return OK;
}
/*  构造一个空栈S */
Status InitStack(LinkStack *S){
    S->top = (LinkStackPtr)malloc(sizeof(StackNode));
    if(!S->top){
        return ERROR;
    }
    S->top = NULL;
    S->count =0;
    return OK;
}
/* 把S置为空栈 */
Status ClearStack(LinkStack *S){
    LinkStackPtr p,q;
    p = S->top;
    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    S->count = 0;
    return OK;
}


/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
Status StackEmpty(LinkStack S)
{ 
        if (S.count==0)
                return TRUE;
        else
                return FALSE;
}
/* 返回S的元素个数，即栈的长度 */
int StackLength(LinkStack S)
{ 
        return S.count;
}
/* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
Status GetTop(LinkStack S,ElemType *e){
    if (S.count <= 0) //S.top == NULL
    {
       return ERROR;
    }
    *e = S.top->data;
    return OK;
}
/* 插入元素e为新的栈顶元素 */
Status Push(LinkStack *S, ElemType e){
    if (S->count >= MAXSIZE )
    {
        return ERROR;
    }
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
    p->data = e;
    p->next = S->top;   /* 把当前的栈顶元素赋值给新结点的直接后继，见图中① */
    S->top = p;          /* 将新的结点s赋值给栈顶指针，见图中② */
    S->count ++;
    return OK;
}


/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
Status Pop(LinkStack *S,ElemType *e){
    if (S->count <= 0) //S.top == NULL
    {
       return ERROR;
    }
    LinkStackPtr p = S->top;
    *e = p->data;
    S->top = p->next;
    free(p);
    S->count--;
    return OK;
}

Status StackTraverse(LinkStack S){
    LinkStackPtr p;
    p = S.top;
    while (p)
    {
       visit(p->data);
       p=p->next;
    }
    printf("\n");
    return OK;
    
}

int main(){
     int j;
    LinkStack s;
    int e;
    if(InitStack(&s)==OK)
            for(j=1;j<=10;j++)
                    Push(&s,j);
    printf("栈中元素依次为：");
    StackTraverse(s);
    Pop(&s,&e);
    printf("弹出的栈顶元素 e=%d\n",e);
    StackTraverse(s);
    printf("栈空否：%d(1:空 0:否)\n",StackEmpty(s));
    GetTop(s,&e);
    printf("栈顶元素 e=%d 栈的长度为%d\n",e,StackLength(s));
    ClearStack(&s);
    printf("清空栈后，栈空否：%d(1:空 0:否)\n",StackEmpty(s));
    return 0;
}