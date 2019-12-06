#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 100000000;
int node[1001][1001];
int dist[1001];
int visit[1001];
int n;
int dijkstra(int start, int end) {
	dist[start] = 0;
	for (int t = start;t <= n;t++) {
		int min = INF;
		int min_v=start;
		for (int i = start; i <= n;i++) {
			if (visit[i] == 0 && min > dist[i]) {
				min = dist[i];
				min_v = i;
			}
		}
		visit[min_v] = 1;
		for (int j = start; j <= n;j++) {
			if (dist[j] > dist[min_v] + node[min_v][j]) {
				dist[j] = dist[min_v] + node[min_v][j];
			}
		}
	}
	return dist[end];
}
int main() {
	int m;
	int u;
	int w;
	int v;
	int a, b;
	scanf("%d", &n);
	scanf("%d", &m);
	for (int o = 1;o <= n;o++) {
		for (int p = 1;p <= n;p++)
			node[o][p] = INF;
	}
	for (int i = 1;i <= m;i++) {
		scanf("%d %d %d", &u, &v, &w);
		node[u][v] = w;
	}
	for (int c = 1;c <= n;c++)
		dist[c] = INF;
	scanf("%d %d", &a, &b);
	printf("%d\n", dijkstra(a,b));
	return 0;
}
