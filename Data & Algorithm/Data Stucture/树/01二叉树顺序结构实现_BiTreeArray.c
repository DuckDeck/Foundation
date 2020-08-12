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
#define MAX_TREE_SIZE 100 /* 二叉树的最大结点数 */

typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */
typedef ElemType SqBitTree[MAX_TREE_SIZE];  /* 0号单元存储根结点  */

typedef struct{
    int level,order; /* 结点的层,本层序号(按满二叉树计算) */
}Position;

ElemType Nil = 0;

Status visit(ElemType c){
    printf("%d ",c);
	return OK;
}
/* 构造空二叉树T。因为T是固定数组，不会改变，故不需要& */
Status InitBitTree(SqBitTree T){
    int i;
    for (i = 0; i < MAX_TREE_SIZE; i++)
    {
        T[i]=Nil;
    }
    return OK;
}
/* 按层序次序输入二叉树中结点的值(字符型或整型), 构造顺序存储的二叉树T */
Status CreateBitTree(SqBitTree T){
    int i = 0;
	printf("请按层序输入结点的值(整型)，0表示空结点，输999结束。结点数≤%d:\n",MAX_TREE_SIZE);
    while (i<10)
    {   
       T[i] = i+1;
       if (i != 0 &&T[(i+1)/2-1]==Nil&&T[i]!=Nil)  /* 此结点(不空)无双亲且不是根 */
       {
           printf("出现无双亲的非根结点%d\n",T[i]);
           exit(ERROR);
       }
       i++;
    }
    while (i<MAX_TREE_SIZE)
    {
        T[i] = Nil; /* 将空赋值给T的后面的结点 */
        i++;
    }
    return OK;
    
}

#define ClearBiTree InitBitTree /* 在顺序存储结构中，两函数完全一样 */
/* 初始条件: 二叉树T存在 */
/* 操作结果: 若T为空二叉树,则返回TRUE,否则FALSE */
Status BiTreeEmpty(SqBitTree T){
    if(T[0]==Nil){
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/* 初始条件: 二叉树T存在。操作结果: 返回T的深度 */
int BiTreeDepth(SqBitTree T){
    int i,j=-1;
    for (i = MAX_TREE_SIZE - 1; i >= 0; i--) /* 找到最后一个结点 */
    {
        if (T[i] != Nil)
        {
            break;
        }
    }
    i++;
    do
    {
        j++;
    } while (i>=pow(2,j)); /* 计算2的j次幂。 */
    return j;
    
}

/* 初始条件: 二叉树T存在 */
/* 操作结果:  当T不空,用e返回T的根,返回OK;否则返回ERROR,e无定义 */
Status Root(SqBitTree T,ElemType *e){
    if (BiTreeEmpty(T))
    {
       return ERROR;
    }
    else{
        *e = T[0];
        return OK;
    }
}
/* 初始条件: 二叉树T存在,e是T中某个结点(的位置) */
/* 操作结果: 返回处于位置e(层,本层序号)的结点的值 */
ElemType Value(SqBitTree T,Position e){
    return T[(int)powl(2,e.level - 1) + e.order - 2];
}
/* 初始条件: 二叉树T存在,e是T中某个结点(的位置) */
/* 操作结果: 给处于位置e(层,本层序号)的结点赋新值value */

Status Assign(SqBitTree T,Position e,ElemType value){
    int i = (int)powl(2,e.level - 1)+e.order-2; /* 将层、本层序号转为矩阵的序号 */
    if (value != Nil && T[(i+1)/2 - 1] == Nil) /* 给叶子赋非空值但双亲为空 */
    {
        return ERROR;
    }
    else if(value == Nil && (T[i*2+1]!= Nil || T[i*2+2]!= Nil)){ /*给双亲赋空值但有叶子（不空） */
        return ERROR;
    }
    T[i] = value;
    return OK;
}


/* 初始条件: 二叉树T存在,e是T中某个结点 */
/* 操作结果: 若e是T的非根结点,则返回它的双亲,否则返回＂空＂ */
ElemType Parent(SqBitTree T,ElemType e){
    int i;
    if (T[0] == Nil) /* 空树 */
    {
       return Nil;
    }
    for (i = 1; i < MAX_TREE_SIZE; i++)  /* 找到e */
    {
       if (T[i] == e)
       {
           return T[(i+1)/2 -1];
       }
       
    }
    return Nil; /* 没找到e */
}
/* 初始条件: 二叉树T存在,e是T中某个结点 */
/* 操作结果: 返回e的左孩子。若e无左孩子,则返回＂空＂ */

ElemType LeftChild(SqBitTree T, ElemType e){
    int i;
    if (T[0] == Nil) /* 空树 */
    {
       return Nil;
    }
    for (i = 0; i <= MAX_TREE_SIZE - 1; i++)  /* 找到e  ,从0开始 要加1*/
    {
       if (T[i] == e )//这里不需要判断孩子有没有出界，因为只要总长度不超就行，后面都是Nil
       {
           return T[i * 2 + 1];
       }
       
    }
    return Nil;
}

/* 初始条件: 二叉树T存在,e是T中某个结点 */
/* 操作结果: 返回e的右孩子。若e无右孩子,则返回＂空＂ */
ElemType RightChild(SqBitTree T, ElemType e){
    int i;
    if (T[0] == Nil) /* 空树 */
    {
       return Nil;
    }
    for (i = 0; i <= MAX_TREE_SIZE - 1; i++)  /* 找到e  ,从0开始 要加1*/
    {
       if (T[i] == e)
       {
           return T[i * 2 + 2];
       }
       
    }
    return Nil;
}


/* 初始条件: 二叉树T存在,e是T中某个结点 */
/* 操作结果: 返回e的左兄弟。若e是T的左孩子或无左兄弟,则返回＂空＂ */
ElemType LeftSibling(SqBitTree T,ElemType e){
    int i;
    if (T[0] == Nil) /* 空树 */
    {
       return Nil;
    }
    for (i = 1; i <= MAX_TREE_SIZE - 1; i++)  /* 找到e  ,从0开始 要加1*/
    {
        if (T[i] == e && i % 2 ==0)  /* 找到e且其序号为偶数(是右孩子) */
        {
           return T[i-1]; //返回上一个孩子 
        }
    }
    return Nil;
}
/* 初始条件: 二叉树T存在,e是T中某个结点 */
/* 操作结果: 返回e的右兄弟。若e是T的右孩子或无右兄弟,则返回＂空＂ */
ElemType RightSibling(SqBitTree T,ElemType e){
    int i;
    if (T[0] == Nil) /* 空树 */
    {
       return Nil;
    }
    for (i = 1; i < MAX_TREE_SIZE ; i++)  /* 找到e  ,从0开始 要加1*/
    {
        if (T[i] == e && i % 2 ==1)  /* 找到e且其序号为奇数(是右孩子) */
        {
           return T[i+1]; //返回下一个孩子 
        }
    }
    return Nil;
}
//前序编
void PreTraverse(SqBitTree T,int e){
    if (BiTreeEmpty(T))
    {
        return;
    }
    visit(T[e]);
    
    if (T[2*e + 1]!= Nil)
    {
       PreTraverse(T,2*e+1);
    }
    if(T[2*e+2] != Nil){
        PreTraverse(T,2*e+2);
    }
}
/* 操作结果: 中序遍历T。 */
void MidTraverse(SqBitTree T,int e){
    
    if (BiTreeEmpty(T))
    {
        return;
    }
    if (T[2*e + 1]!= Nil)
    {
        MidTraverse(T,2*e+1);
    }
    visit(T[e]);
    if(T[2*e+2] != Nil){
        MidTraverse(T,2*e+2);
    }
}
/* 操作结果: 后序遍历T。 */
void BackTraverse(SqBitTree T,int e){
    if (BiTreeEmpty(T))
    {
        return;
    }
    if (T[2*e + 1]!= Nil)
    {
        BackTraverse(T,2*e+1);
    }
    if(T[2*e+2] != Nil){
        BackTraverse(T,2*e+2);
    }
    visit(T[e]);
}

/* 层序遍历二叉树 */
void LevelTraverse(SqBitTree T){
    //为种线性的结构，直接顺序来就行了
    int i;
    for ( i = 0; i < MAX_TREE_SIZE; i++)
    {
        if (T[i]!=Nil)
        {
           visit(T[i]);
        }
    }
    printf("\n");    
}

int main(){

    Status i;
    Position p;
    ElemType e;
    SqBitTree T;
    InitBitTree(T);
    CreateBitTree(T);
	printf("建立二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
    i = Root(T,&e);
    if(i)
		printf("二叉树的根为：%d\n",e);
	else
		printf("树空，无根\n");
	printf("层序遍历二叉树:\n");
	LevelTraverse(T);
	printf("前序遍历二叉树:\n");
	PreTraverse(T,0);
	printf("中序遍历二叉树:\n");
	MidTraverse(T,0);
	printf("后序遍历二叉树:\n");
	BackTraverse(T,0);
	printf("修改结点的层号3本层序号2。");
	p.level=3;
	p.order=2;
	e=Value(T,p);
	printf("待修改结点的原值为%d请输入新值:50 ",e);
	e=50;
	Assign(T,p,e);
    	printf("前序遍历二叉树:\n");
	PreTraverse(T,0);
	printf("结点%d的双亲为%d,左右孩子分别为",e,Parent(T,e));
	printf("%d,%d,左右兄弟分别为",LeftChild(T,e),RightChild(T,e));
	printf("%d,%d\n",LeftSibling(T,e),RightSibling(T,e));
	ClearBiTree(T);
	printf("清除二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T,&e);
	if(i)
		printf("二叉树的根为：%d\n",e);
	else
		printf("树空，无根\n");
	


    
    return 0;
}
