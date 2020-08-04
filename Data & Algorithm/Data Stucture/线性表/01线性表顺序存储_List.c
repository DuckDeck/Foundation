
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

typedef int Status;          /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;        /* ElemType类型根据实际情况而定，这里假设为int */


Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}

typedef struct
{
	ElemType data[MAXSIZE];        /* 数组，存储数据元素 */
	int length;                                /* 线性表当前长度 */
}SqList;

/* 初始化顺序线性表 */
Status InitList(SqList *L) 
{ 
    L->length=0;
    return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Status ListEmpty(SqList L)
{ 
	if(L.length==0)
		return TRUE;
	else
		return FALSE;
}


/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status ClearList(SqList *L)
{ 
    L->length=0;
    return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(SqList L)
{
        return L.length;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值,注意i是指位置，第1个位置的数组是从0开始 */
Status GetElem(SqList L,int i,ElemType *e)
{
    if(L.length==0 || i<1 || i>L.length)
            return ERROR;
    *e=L.data[i-1];

    return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
int LocateElem(SqList L,ElemType e)
{
    int i;
    if (L.length==0)
            return 0;
    for(i=0;i<L.length;i++)
    {
            if (L.data[i]==e)
                    break;
    }
    if(i>=L.length)
            return 0;

    return i+1;
}

/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
Status ListInsert(SqList *L,int i,ElemType e){
    int k;
    if(L->length == MAXSIZE){
        printf("表已经滿了");
        return ERROR;
    }
    if(i<0||i>L->length){
        printf("i比第一位置小或者比最后一位置后一位置还要大时");
        return ERROR;
    }
    if (i<L->length)
    {
       for (k= L->length - 1; k > i; k--)
       {
           L->data[k+1]=L->data[k];
           // printf("第%d个数据向后面移一位\n",k);
       }
    }
    //printf("写入%d \n",e);
    L->data[i] = e;
    L->length++;
    return OK;
}
/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */

Status ListDelete(SqList *L,int i,ElemType *e){
    int k;
    if (L->length <= 0){
        printf("表是空的");
        return ERROR;
    }
      if(i<0||i>L->length){
        printf("i比第一位置小或者比最后一位置后一位置还要大时");
        return ERROR;
    }
    
    *e = L->data[i];   //将要删除的值交给e
    if (i<L->length)
    {
       for (k= i+1; k < L->length ; k++)
       {
           L->data[k-1]=L->data[k]; //从该位置开始，将后面的item全部向前移动
       }
    }
    L->length--;
    return OK;
}
/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */

Status ListTraverse(SqList L){
    int i;
    for ( i = 0; i < L.length; i++)
    {
       visit(L.data[i]);
    }
    printf("\n");
    return OK;
}



/*将B表且不在A表的数据添加到A表*/
Status Union(SqList *A,SqList B){
    int len_a, len_b;
    ElemType e;
    len_a = ListLength(*A);
    len_b = ListLength(B);
    for (int i = 0; i < len_b; i++)
    {
        GetElem(B,i,&e);
        if (!LocateElem(*A,e))
        {
            ListInsert(A,len_a++,e);
        }
        
    }
}


int main(){
    printf("01线性表顺序存储_List  \n");
    SqList L ;
    ElemType e;
    Status i;
    int j,k;
    i = InitList(&L);
    printf("初始化后：L.lenfth=%d \n",L.length);
    for (j = 0; j < 10; j++)
    {
        ListInsert(&L,j,j);
    }
    printf("在L的表头依次插入1～10后：L.data=%d \n",L.length);
    ListTraverse(L);
    ListDelete(&L,2,&e);
    ListTraverse(L);
    printf("\n");
    SqList L2;
    InitList(&L2);
    for (j = 33; j < 40; j++)
    {
        ListInsert(&L2,j-33,j);
    }
    ListTraverse(L2);
    Union(&L,L2);
    ListTraverse(L);
    ListDelete(&L,1,&e);
    ListTraverse(L);
 
    return 0;
}