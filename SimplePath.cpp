/*设计算法输出顶点i到顶点j的全部路径*/
#include <stdio.h>
#include <stdlib.h>

#define N 5

/*图结构 邻接矩阵表示法*/
typedef struct Graph{
	char V[N];
	int E[N][N];
	int VNum = N;
}Graph;

void InitG(Graph *G) {
	int n = G->VNum;
	printf("请输入%d个顶点(单个字符):",n);
	for (int i = 0; i < n; i++) {
		scanf_s("%c", &G->V[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n;j++) {
			if (i == j) {
				G->E[i][j] = 0;
			}
			else {
				int m;
				printf("\n顶点%c与顶点%c之间是否存在边？", G->V[i], G->V[j]);
				printf("\n若存在边请输入1,不存在则输入0:");
				scanf_s("%d", &m);
				if (m == 0) {
					G->E[i][j] = G->E[j][i] = 0;
				}
				else {
					G->E[i][j] = G->E[j][i] = 1;
				}
			}
		}
	}
}

/*寻找路径*/
void findpath(Graph *G,int i,int j,int *visited,char *path,int n) {
	path[n] = G->V[i];
	visited[i] = 1;
	if (n + 1 < N) path[n + 1] = '\0';
	if (path[n] == G->V[j]) {
		int ii = 0;
		while (path[ii] != '\0'&&ii<N) {
			printf("%c", path[ii]);
			ii++;
		}
		printf("\n");
		visited[j] = 0;
	}
	else {
		for (int k = 0; k < N; k++) {
			if (!visited[k]&&G->E[i][k]==1) {
				findpath(G, k, j, visited, path, n + 1);
			}
		}
		visited[i] = 0;
		path[n] = '\0';
	}
}

void main(void) {
	Graph G;
	InitG(&G);
	int visited[N] = { 0 };
	char path[N];
	findpath(&G, 0, 4, visited, path, 0);
}