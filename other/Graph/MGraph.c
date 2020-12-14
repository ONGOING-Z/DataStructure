#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <math.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100  // ��󶥵���
#define INFINITY 65535  // ���������

typedef int Status; // �������� 
typedef char VertexType;  // ��������
typedef int EdgeType;  // ����Ȩֵ����
typedef int Boolean;
Boolean visited[MAX];  // ���ʱ�־���飬��ֵΪ0�����ʹ���Ϊ1

/* ͼ���ڽӾ���洢�ṹ */
typedef struct
{
    VertexType vexs[MAXVEX];  // �����
    EdgeType arc[MAXVEX][MAXVEX];  // �ڽӾ���
    int numVertexes, numEdges;  // ͼ�е�ǰ�����������
} MGraph;

/* ����������ͼ���ڽӾ����ʾ */
void CreateMGraph(MGraph *G)
{
    int i, j, k, w;
    printf("���붥�����ͱ���:\n");
    scanf("%d, %d", &G->numVertexes, &G->numEdges);
    // �����
    for(i=0; i<G->numVertexes; i++)
        scanf(&G->vexs[i]);
    // �ڽӾ����ʼ��
    for(i=0; i<G->numVertexes; i++)
        for(j=0; j<G->numVertexes; j++)
            G->arc[i][j] = INFINITY;
    for(k=0; k<G->numEdges; k++)
    {
        printf("�����(vi, vj)���±�i, j��Ȩֵw:\n");
        scanf("%d, %d, %d", &i, &j, &w);
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];
    }
}

/* �ڽӾ����������ȵݹ��㷨 */
void DFS(MGraph G, int i)
{
    int j;
    visited[i]  = TRUE;
    printf("%c ", G.vexs[i]);  // ��ӡ����
    for(j=0; j<G.numVertexes; j++)
        if(G.arc[i][j] == 1 && !visited[j])
            DFS(G, j);  // �ݹ�����ڽӶ���
}

/* �ڽӾ������ȱ������� */
void DFSTraverse(MGraph G)
{
    int i;
    for(i=0; i<G.numVertexes; i++)
        visited[i] = FALSE;  // ��ʼ���ж���״̬Ϊδ����״̬
    for(i=0; i<G.numVertexes; i++)
        if(!visited[i])
            DFS(G, i);
}

/* �ڽӾ���Ĺ�ȱ����㷨 */
void BFSTraverse(MGraph M)
{
	int i, j;
	Queue Q;
	for(i=0; i<G.numVertexes; i++)
	    visited[i] = FALSE;
	InitQueue(&Q);  // ��ʼ����������
	for(i=0; i<G.numVertexes; i++)  // ѭ��ÿһ������
	{
		if(!visited[i])
		{
			visited[i] = TRUE;
			printf("%c ", G.vexs[i]);  // ��ӡ����
			EnQueue(&Q, i);            // ���˶��������
			while(!QueueEmpty(Q))      // ����ǰ���в�Ϊ��
			{
				DeQueue(&Q, &i);       // ������Ԫ�س�����
				for(j=0; j<G.numVertexes; j++)
				{
					if(G.arc[i][j] == 1 && !visited[j])
					{
						visited[j] = TRUE;
						printf("%c ", G.vex[j]);    // ��ӡ����
						EnQueue(&Q, j); 
					}
				} 
			} 
		}
	} 
}

int main(void)
{
	MGraph G;
	CreateMGraph(&G);
	return 0;
} 
