#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <time.h>
#include <math.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100  // ��󶥵���
#define INFINITY 65535  // ���������

typedef int Status;  // �������� 
typedef char VertexType;  // ��������
typedef int EdgeType;  // ����Ȩֵ����

typedef int Boolean;
Boolean visited[MAX];  // ���ʱ�־���飬��ֵΪ0�����ʹ���Ϊ1

// �߱���
typedef struct EdgeNode
{
    int adjvex;  // �ڽӵ��򣬴洢�ö����Ӧ�±�
    EdgeType weight;  // �洢Ȩֵ
    struct EdgeType *next;  // ����ָ����һ���ڽӵ�
} EdgeNode;

// �������
typedef struct VertexNode
{
    VertexType data;  // �����򣬴洢������Ϣ
    EdgeNode *firstedge;  // �߱�ͷָ��
} VertexNode, AdjList[MAXVEX];

typedef struct 
{
    AdjList adjList;
    int numVertexes, numEdges;  // ͼ�е�ǰ�������ͱ���
} GraphAdjList;

/* ����ͼ���ڽӱ�ṹ */
void CreateALGraph(GraphAdjList *G)
{
    int i, j, k;
    EdgeNode *e;
    printf("���붥�����ͱ���:\n");
    scanf("%d, %d", &G->numVertexes, &G->numEdges);
    // ���������
    for(i=0; i<G->numVertexes; i++)
    {
        scanf(&G->adjList[i].data);  // ���붥����Ϣ
        G->adjList[i].firstedge = NULL;  // ���߱���Ϊ��
    }

    // �����߱�
    for(k=0; k<G->numEdges; k++)
    {
        printf("�����(vi, vj)�ϵĶ������:\n");
        scanf("%d, %d", &i, &j);
        e = (EdgeNode *)malloc(sizeof(EdgeNode)); // ����ռ����ɱ߱���
        // ͷ�巨
        e->adjvex = j;
        e->next = G->adjList[i].firstedge;
        G->adjList[i].firstedge = e;

        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = i;
        e->next = G->adjList[j].firstedge;
        G->adjList[j].firstedge = e;
    }
}

/* �ڽӱ��������ȵݹ��㷨 */
void DFS(GraphAdjList GL, int i)
{
    EdgeNode *p;
    visited[i] = TRUE;
    printf("%c ", GL->adjList[i].data);  // ��ӡ����
    p = GL->adjList[i].firstedge;
    while(p)
    {
        if(!visited[p->adjvex])
            DFS(GL, p->adjvex);  // ���ڽӶ���ݹ����
        p = p->next;
    }
}

/* �ڽӱ����ȱ������� */
void DFSTraverse(GraphAdjList GL)
{
    int i;
    for(i=0; i<GL.numVertexes; i++)
        visited[i] = FALSE;  // ��ʼ�����ж���״̬Ϊδ����
    for(i=0; i<GL.numVertexes; i++)
        if(!visited[i])
            DFS(GL, i);
}

/* �ڽӱ�Ĺ�����ȱ��� */
void BFSTraverse(GraphAdjList GL) 
{
	int i;
	EdgeNode *p;
	Queue Q;
	for(i=0; i<GL->numVertexes; i++)
	    visited[i] = FALSE;    // ��ʼ�����ж���״̬Ϊδ����
	InitQueue(&Q);
	for(i=0; i<GL->numVertexes; i++)
	{
		if(!visited[i])
		{
			visited[i] = TRUE;
			printf("%c ", GL->adjList[i].data);  // ��ӡ����
			EnQueue(&Q, i);
			while(!QueueEmpty(Q))
			{
				DeQueue(&Q, &i);
				p = GL->adjList[i].firstedge;  // �ҵ���ǰ����߱�����ͷָ��
				while(p)
				{
					if(!visited[p->adjvex])
					{
						visited[p->adjvex] = TRUE;
						printf("%c ", GL->adjList[p->adjvex].data);
						EnQueue(&Q, p->adjvex);    // ����������� 
					}
					p = p->next;
				 } 
			 } 
		}
	 } 
}

int main(void) 
{
	GraphAdjList G;
	CreateALGraph(&G);
	return 0;
}
