#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int node[1000][1000];
int m, n, v, row, col;
int Q[1000];
int visit[1000];
int rear = 0;
int front = 0;
void dfs(int now) {
	visit[now] = 1;
	printf("%d ", now);
	for (int j = 1; j <= n; j++) {
		int next = j;
		if (node[now][next] == 1) {
			if (visit[next] == 0) {
				visit[next] = 1;
				dfs(next);
			}
		}
	}
}
void bfs(int start) {
	int visit[1000];
	visit[start] = 2;
	int i;
	Q[rear++] = start;
	while(front<rear){
		int now = Q[front++];
		printf("%d ", now);
		for (i = 1;i <= n;i++) {
			if (node[now][i] == 1) {
				if (visit[i] !=2) {
					visit[i] = 2;
					Q[rear++] = i;
				}
			}
		}
		}  
}
int main() {
	scanf("%d %d %d", &n, &m, &v);
	for (int i = 0;i < m;i++) {
		scanf("%d %d", &row, &col);
		node[row][col] = node[col][row] = 1;
	}
	dfs(v);
	printf("\n");
	bfs(v);
	return 0;
}