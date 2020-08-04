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

typedef struct 
{
    /* data */
    ElemType data[MAXSIZE];
    int top1;           /* 栈1栈顶指针 */
    int top2;           	/* 栈2栈顶指针 */
} SqDoubleStack;

Status visit(ElemType e){
     printf("%d ",e);
    return OK;
}
/*  构造一个空栈S */

Status InitStack(SqDoubleStack *S){
    S->top1 = -1;
    S->top2 = MAXSIZE;
    return OK;
}
/* 把S置为空栈 */
Status ClearStack(SqDoubleStack *S)
{ 
        S->top1=-1;
        S->top2=MAXSIZE;
        return OK;
}

/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
Status StackEmpty(SqDoubleStack S)
{ 
        if (S.top1==-1 && S.top2==MAXSIZE)
                return TRUE;
        else
                return FALSE;
}

/* 返回S的元素个数，即栈的长度 */
int StackLength(SqDoubleStack S)
{ 
       return (S.top1+1)+(MAXSIZE-1-S.top2);
}

/* 插入元素e为新的栈顶元素 */
Status Push(SqDoubleStack *S,ElemType e,int stackNum){
    if (S->top1 + 1 == S->top2 ) /* 栈已满，不能再push新元素了 */
    {
        return ERROR;
    }
    if (stackNum == 1)  /* 栈1有元素进栈 */
    {
        S->top1++;
        S->data[S->top1] = e;   /* 若是栈1则先top1+1后给数组元素赋值。 */
    }
    else if (stackNum == 2){    /* 栈2有元素进栈 */
        S->top2--;
        S->data[S->top2]= e;     /* 若是栈2则先top2-1后给数组元素赋值。 */
    }
    return OK;
}
/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */

Status Pop(SqDoubleStack *S,ElemType *e,int stackNum){

    if (stackNum == 1)
    {
        if (S->top1 == -1)
        {
            return ERROR;  /* 说明栈1已经是空栈，溢出 */
        }
       *e = S->data[S->top1];   /* 将栈1的栈顶元素出栈 */
       S->top1--;
    }
    else  if (stackNum == 2)
    {
        if (S->top2 == MAXSIZE)
        {
            return ERROR;    /* 说明栈2已经是空栈，溢出 */
        }   
       *e = S->data[S->top2];       /* 将栈2的栈顶元素出栈 */
       S->top2++;
    }

}

Status StackTraverse(SqDoubleStack S){
    int i= 0;
    while (i<S.top1)
    {
        visit(S.data[i++]);
    }
    i=S.top2; //因为有可能不滿
    while (i<MAXSIZE)
    {
       visit(S.data[i++]);
    }
    printf("\n")    ;
    return OK;
    
}

int main(){
      int j;
    SqDoubleStack s;
    int e;
    if(InitStack(&s)==OK)
    {
            for(j=1;j<=5;j++)
                    Push(&s,j,1);
            for(j=MAXSIZE;j>=MAXSIZE-2;j--)
                    Push(&s,j,2);
    }
    printf("栈中元素依次为：");
    StackTraverse(s);

    for(j=6;j<=MAXSIZE-2;j++)
        Push(&s,j,1);

    printf("栈中元素依次为：");
    StackTraverse(s);

    printf("栈满否：%d(1:否 0:满)\n",Push(&s,100,1));

    
    ClearStack(&s);
    printf("清空栈后，栈空否：%d(1:空 0:否)\n",StackEmpty(s));

    return 0;
}