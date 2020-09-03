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


#define MAXSIZE 48

void strsort(char *strings[], int num);
char *s_gets(char *s, int n);

typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */

typedef char String[MAXSIZE+1]; /*  0号单元存放串的长度 */


/* 生成一个其值等于chars的串T */
Status StrAssign(String T,char *chars)
{ 
	int i;
	if(strlen(chars)>MAXSIZE)
		return ERROR;
	else
	{
		T[0]=strlen(chars);
		for(i=1;i<=T[0];i++)
			T[i]=*(chars+i-1);
		return OK;
	}
}

/* 由串S复制得串T */
Status StrCopy(String T,String S)
{ 
	int i;
	for(i=0;i<=S[0];i++)
		T[i]=S[i];
	return OK;
}

/* 若S为空串,则返回TRUE,否则返回FALSE */
Status StrEmpty(String S)
{ 
	if(S[0]==0)
		return TRUE;
	else
		return FALSE;
}

/*  初始条件: 串S和T存在 */
/*  操作结果: 若S>T,则返回值>0;若S=T,则返回值=0;若S<T,则返回值<0 */
int StrCompare(String S,String T)
{ 
	int i;
	for(i=1;i<=S[0]&&i<=T[0];++i)
		if(S[i]!=T[i])
			return S[i]-T[i];
	return S[0]-T[0];
}

/* 返回串的元素个数 */
int StrLength(String S)
{ 
	return S[0];
}


int main(){
    String *a ;
   
    printf(a);
    printf(*a);
    printf(&a);
}