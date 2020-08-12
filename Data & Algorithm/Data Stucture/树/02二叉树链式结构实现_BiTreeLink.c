#include "stdio.h"    
#include "stdlib.h"   
#include <sys/uio.h>
#include "math.h"  
#include "time.h"
#include "string.h"
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */

int Index = 1; 
typedef char String[7];

String str;
Status StrAssign(String T,char *c){
    int i;
    if (strlen(c) > MAXSIZE)
    {
       return ERROR;
    }
    else{
        T[0]=strlen(c);
        for (i = 1; i < T[0]; i++)
        {
          T[i] = *(c+i-1);
        }
        return OK;
        
    }
}


typedef char ElemType;
ElemType Nil=' '; /* 锟街凤拷锟斤拷锟皆空革拷锟轿拷锟� */
Status visit(ElemType e){
    printf("%c ",e);
    return OK;
}


typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

Status InitBiTree(BiTree *T)
{
    *T = NULL;
    return OK;
}

Status BiTreeEmpty(BiTree T)
{ 
	if(T)
		return FALSE;
	else
		return TRUE;
}

void DestroyBiTree(BiTree *T){
    if(*T){
        if((*T)->lchild){
            DestroyBiTree(&(*T)->lchild);
        }
        if((*T)->rchild){
             DestroyBiTree(&(*T)->rchild);
        }
        free(*T);
        *T = NULL;
    }
}

void CreateBiTree(BiTree *T){
    if (Index >= str[0])
    {
        return;
    }
    
    ElemType ch;
    ch = str[Index++];
    if (ch == '#')
    {
        *T = NULL;
    }
    else{
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (!*T)
        {
            exit(OVERFLOW);
        }
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}
#define ClearBiTree DestroyBiTree
int BiTreeDepth(BiTree T){
    int i,j;
    if (!T)
    {
        return 0;
    }
    if (T->lchild){
        i = BiTreeDepth(T->lchild);
    }
    else
    {
        i = 0;
    }
    if (T->rchild)
    {
       j=BiTreeDepth(T->rchild);
    }
    else
    {
        j=0;
    }
    return i> j?i+1:j+1;
}

ElemType Root(BiTree T){
    if (BiTreeEmpty(T))
    {
       return Nil;
    }
    return T->data;
    
}

ElemType Value(BiTree p)
{
	return p->data;
}
void Assign(BiTree p,ElemType value)
{
	p->data=value;
}

void PreTraverse(BiTree T){
    if (T == NULL)
    {
        return;
    }
    visit(T->data);
    PreTraverse(T->lchild);
    PreTraverse(T->rchild);
}

void MidTraverse(BiTree T){
    if (T == NULL)
    {
        return;
    }
    
    PreTraverse(T->lchild);
    visit(T->data);
    PreTraverse(T->rchild);
}

void BackTraverse(BiTree T){
    if (T == NULL)
    {
        return;
    }
   
    PreTraverse(T->lchild);
    PreTraverse(T->rchild);
     visit(T->data);
}



int main(){
    int i;
    BiTree T;
    ElemType e1;
    InitBiTree(&T);
    // StrAssign(str,"ABDH#K###E##CFI###G#J##");
    StrAssign(str,"ABC#EF#");
    CreateBiTree(&T);
	printf("建立二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
    e1=Root(T);
    if(e1)
		printf("二叉树的根为：%d\n",e1);
	else
		printf("树空，无根\n");

    return 0;
}