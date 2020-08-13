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
#define MAXSIZE 9 /* 存储空间初始分配量 */
#define MAXEDGE 15

#define MAXVEX 9

#define INFINITY 65535

typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef char VertexType;/* 顶点类型应由用户定义  */
typedef int EdgeType;  /* 边上的权值类型应由用户定义 */

typedef struct{
    
    VertexType vexs[MAXVEX];   /* 顶点表 */
    EdgeType arc[MAXVEX][MAXVEX]; /* 邻接矩阵，可看作边表 */
    int numNodes,numEdges;/* 图中当前的顶点数和边数  */
}MGraph;

/* 循环队列的顺序存储结构 */
typedef struct
{
	int data[MAXSIZE];
	int front;    	/* 头指针 */
	int rear;		/* 尾指针，若队列不空，指向队列尾元素的下一个位置 */
}Queue;
/* 若队列Q为空队列,则返回TRUE,否则返回FALSE */
Status QueueEmpty(Queue Q)
{ 
	if(Q.front==Q.rear) /* 队列空的标志 */
		return TRUE;
	else
		return FALSE;
}
/* 若队列未满，则插入元素e为Q新的队尾元素 */

Status InitQueue(Queue *Q){
    Q->front = 0;
    Q->rear =0;
    return OK;
}
void CreatedMGraph(MGraph *G){
    int i,j,k,w;
    printf("输入顶点数和边数:\n");
    scanf("%d,%d",&G->numNodes,&G->numEdges);/* 输入顶点数和边数 */
    for ( i = 0; i < G->numNodes; i++)
    {
        scanf(&G->vexs[i]);
    }
    for ( i = 0; i < G->numEdges; i++)
    {
       for ( j = 0; j < G->numEdges; j++)
       {
           G->arc[i][j] = INFINITY;
       }
    }
    for (k = 0; k < G->numEdges; k++)
    {
        printf("输入边(vi,vj)上的下标i，下标j和权w:\n");
        scanf("%d,%d,%d",&i,&j,&w);
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];
    }		
}



Status EnQueue(Queue *Q,int e){
    if ((Q->rear+1)%MAXSIZE == Q->front)
    {
       return ERROR;
    }
    Q->data[Q->rear]=e;
    Q->rear=(Q->rear+1)%MAXSIZE;
    return OK;
}

Status DeQueue(Queue *Q,int *e){
    if ((Q->rear+1)%MAXSIZE == Q->front)
    {
       return ERROR;
    }
    *e = Q->data[Q->front];
    Q->front=(Q->front +1) % MAXSIZE;
    return OK;
}

void CreateMGraphSolid(MGraph *G){
    int i,j;
    G->numEdges = 15;
    G->numNodes = 9;
    	/* 读入顶点信息，建立顶点表 */
	G->vexs[0]='A';
	G->vexs[1]='B';
	G->vexs[2]='C';
	G->vexs[3]='D';
	G->vexs[4]='E';
	G->vexs[5]='F';
	G->vexs[6]='G';
	G->vexs[7]='H';
	G->vexs[8]='I';

    for (i = 0; i < G->numNodes; i++)
    {
        for (j = 0; j < G->numNodes; j++)
        {
            G->arc[i][j] = 0;
        }
        
    }
    
    	G->arc[0][1]=1;
	G->arc[0][5]=1;

	G->arc[1][2]=1; 
	G->arc[1][8]=1; 
	G->arc[1][6]=1; 
	
	G->arc[2][3]=1; 
	G->arc[2][8]=1; 
	
	G->arc[3][4]=1;
	G->arc[3][7]=1;
	G->arc[3][6]=1;
	G->arc[3][8]=1;

	G->arc[4][5]=1;
	G->arc[4][7]=1;

	G->arc[5][6]=1; 
	
	G->arc[6][7]=1; 

    for (i = 0; i < G->numNodes; i++)
    {
        for (j = i; j < G->numNodes; j++)
        {
            G->arc[j][i] = G->arc[i][j]; 
        }
        
    }
    

}

typedef int Boolean;

Boolean visited[MAXVEX]; /* 访问标志的数组 */
/* 邻接矩阵的深度优先递归算法 */
void DFS(MGraph G,int i){
    int j;
    visited[i] = TRUE;
 	printf("%c ", G.vexs[i]);/* 打印顶点，也可以其它操作 */
    for (j = 0; j < G.numNodes; j++)
    {
        if (G.arc[i][j] == 1 && !visited[j])
        {
            DFS(G,j);
        }
    }
}
/* 邻接矩阵的深度遍历操作 */

void DFSTraverse(MGraph G){
    int i;
    for (i = 0; i < G.numNodes; i++)
    {
        visited[i] = FALSE;
    }
    for (i = 0; i < G.numNodes; i++)
    {
       if (!visited[i])
       {
           DFS(G,i);
       }
    }    
}

void BFSTraverse(MGraph G){
    int i,j;
    Queue Q;
    for (i = 0; i < G.numNodes; i++)
    {
       visited[i] = FALSE;
    }
    InitQueue(&Q);
    for (i = 0; i < G.numNodes; i++)
    {
        if (!visited[i])
        {
            visited[i]=TRUE;
            printf("%c ", G.vexs[i]);/* 打印顶点，也可以其它操作 */
            EnQueue(&Q,i);
            while (!QueueEmpty(Q))
            {
                DeQueue(&Q,&i);
                for (j = 0; j < G.numNodes; j++)
                {
                    if (G.arc[i][j]==1 && !visited[j])
                    {
                        visited[j]=TRUE;
                        printf("%c ",G.vexs[j]);
                        EnQueue(&Q,j);
                    }
                    
                }
                
            }
            
        }
        
    }
    
}
int main(){
    MGraph G;
    CreateMGraphSolid(&G);
    printf("深度\n");
    DFSTraverse(G);
    printf("\n");
    printf("广度\n");
    BFSTraverse(G);
    return 0;
}