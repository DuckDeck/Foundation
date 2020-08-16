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

#define MAX_LENGTH_INSERT_SORT 7 /* 用于快速排序时判断是否选用插入排序阙值 */


typedef int Status;

#define MAXSIZE 9  /* 用于要排序数组个数最大值，可根据需要修改 */

typedef struct{
    int r[MAXSIZE];
    int length;
}SqList;

int changeCount = 0;

void swap(SqList *L,int i,int j){
    int tmp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = tmp;
    changeCount += 1;
}

void print(SqList L)
{
	int i;
	for(i=0;i<L.length;i++)
		printf("%d,",L.r[i]);
	
	printf("\n");
}

/* 对顺序表L作交换排序（冒泡排序初级版） */
void BubbleSort0(SqList *L){
    int i,j;
    for (i = L->length - 1; i>= 0; i--)
    {
        for (j = i-1; j>=0; j--)
        {
            if (L->r[j]>L->r[i])
            {
                swap(L,i,j);
            }            
        }
    }
}
/* 对顺序表L作交换排序（改进的冒泡排序） */
void BubbleSort1(SqList *L){
    int i,j;
    Status flag = TRUE;
    for (i = L->length - 1; i>= 0 && flag; i--)
    {
        flag = FALSE;
        for (j = i-1; j>=0; j--)
        {
            if (L->r[j]>L->r[i])
            {
                swap(L,i,j);
                flag = TRUE;
            }            
        }
    }
}
//简单选择排序
void SelectSort(SqList *L){
    int i,j,min;
    //从每0个数开始一个一个选择最小的数
    for (i = 0; i < L->length; i++)
    {
        min = i;  //假设第i个最小
        for (j = i+1; j < L->length; j++)
        {
            if (L->r[min]>L->r[j]) //如果有更小的
            {
                min = j;
            }
        }
        if (i != min) //判断有没有更改最小的那个数的位置
        {
            swap(L,i,min); //有更改说明后面的数是最小的，将两者交换公位置
        }
    }
}
/* 对顺序表L作直接插入排序 */
void InsertSort(SqList *L){
    int i,j,tmp;
    for ( i = 1; i < L->length; i++)
    {
       if (L->r[i]<L->r[i-1]) //如果后面一个数比前一个数小，那么就要把为个数插到前面的有序数组里的合适位置
       {
           tmp = L->r[i]; //把这个数保存在临时变量里
            for (j = i-1; L->r[j] > tmp && j >= 0; j--)  //tmp一个一个和前一数比，直到比前一个数小，而在同时，将比其大的数向后移一个位置，方面插入这个数.注意j不能小于0
            {
                L->r[j+1] = L->r[j]; //将这个数后移动，一次移动一个，直到前面的娄比tmp小为止
            }
            L->r[j+1] = tmp; //这个时侯j刚好是前面比tmp小的数，后面比tmp 大的数，将这个数插入
       }
    }
    
}

void ShellSort(SqList *L){
    int i,j,tmp;
    int increment = L->length; //设置增量为数组长度
    do
    {
        increment = increment / 3; //重新设置增量为其三分之一
        for (i = increment; i < L->length; i++) //从增量处开始处理
        {
            if (L->r[i]<L->r[i-increment]) //如果该处比增量的前一个数小
            {
                tmp = L->r[i]; //后一个数保存为tmp
                for (j = i-increment; j>=0&&tmp < L->r[j]; j -= increment)  //把后面的那个数，也就是tmp和前面的数比较，如果tmp小，那么把前面的数插到后面去
                {
                    L->r[j+increment] = L->r[j];  //把前面的数插到后面去
                }
                L->r[j+increment] = tmp;  //这个时侯的j应该是比较小的，在前面，所以要把tmp放进来
            }
            
        }
        
    } while (increment > 1);
}
int Partition(SqList *L,int low,int high){
        int pivotKey = L->r[low];
        while (low < high)
        {
            while (low < high && L->r[high] > pivotKey)
            {
               high --;
            }
            swap(L,low,high);
            while (low<high&&L->r[low]<=pivotKey)
            {
                low ++;
            }
            swap(L,low,high);
        }
        return low;
}
void QSort(SqList *L,int low,int high){
    int pivot;
    if (low < high)
    {
       pivot = Partition(L,low,high);
       QSort(L,low,pivot - 1);
       QSort(L,pivot + 1,high);
    }
}
/* 对顺序表L作快速排序 */
void QuickSort(SqList *L){
    QSort(L,0,L->length-1);
}




int main(){
    int i;
    int d[9]={53,23,91,30,70,2,80,61,12};
    SqList l0,l1,l2,l3,l4,l5,l6,l7,l8,l9,l10;
   
   for(i=0;i<9;i++)
     l0.r[i]=d[i];
   l0.length=9;
   l1=l2=l3=l4=l5=l6=l7=l8=l9=l10=l0;
    printf("排序前:\n");
    print(l0);
    BubbleSort0(&l0);
    printf("初级冒泡排序:\n");
    print(l0);
    printf("交换了%d次\n",changeCount);
    changeCount = 0;
    BubbleSort1(&l1);
    printf("改进冒泡排序:\n");
    print(l1);
    printf("交换了%d次\n",changeCount);
    changeCount = 0;
    SelectSort(&l2);
    printf("简单选择排序:\n");
    print(l2);
    printf("交换了%d次\n",changeCount);
    changeCount = 0;
    InsertSort(&l3);
    printf("简单插入排序:\n");
    print(l3);
    
    ShellSort(&l4);
    printf("SHELL排序:\n");
    print(l4);

     QuickSort(&l8);
    printf("快速排序:\n");
    print(l8);

}