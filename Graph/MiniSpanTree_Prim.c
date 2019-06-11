/* Prim�㷨������С������ */
void MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	ing adjvex[MAXVEX];  // ������ض����±�
	int lowcost[MAXVEX];  // ������ض���ߵ�Ȩֵ
	lowcost[0] = 0;       // ��ʼ����һ��ȨֵΪ0������ v0 �Ѽ�����С������
	                      //  lowcostΪ0�����Ǵ��±�Ķ����Ѽ���������
	adjvex[0] = 0;        
	// ��ʼ��
	for(i=0; i<G.numVertexes; i++)
	{
		lowcost[i] = G.arc[0][i];  // ���ڽӾ���ĵ�һ�ж�������
		adjvex[i] = 0;             // ��ʼ����Ϊ v0 ���±�
	}
	for(i=0; i<G.numVertexes; i++)
	{
		min = INFINITY;  // ��ʼ����СȨֵΪ�����
		j = 1; k = 0;
		while(j < G.numVertexes)  // ѭ��ȫ������
		{
			if(lowcost[j] != 0 && lowcost[j] < min)
			// ���Ȩֵ��Ϊ0���˱����Ѿ����������Ľ�㣬�ʲ�������СȨֵ�ıȽ�
			{
				min = lowcost[j];
				k = j;
			} 
			j++; 
		}
		printf("(%d, %d)", adjvex[k], k);  // ��ӡ��ǰ�������Ȩֵ��С��
		lowcost[k] = 0;                    // ����ǰ�����Ȩֵ����Ϊ0�������Ѿ��������
		
		for(j=1; j<G.numVertexes; j++)
		{
			if(lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
			{
				lowcost[j] = G.arc[k][j];
				adjvex[j] = k;
			}
		} 
	} 
} 
