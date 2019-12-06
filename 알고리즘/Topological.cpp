//2015004439_±èÀçÈ«_508
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int link[1000][1000];
int visit[1000];
int finish[1000];
int sort[1000];
int m;
int i = 1;
int from, to;
void dfs(int start, int n) {
	int now = start;
	visit[now] = 1;
	int next;
	for (int j = 1; j <= n; j++) {
		next = j;
		if (link[now][next] == 1) {
			if (visit[next] != 1) {
				visit[next] = 1;
				dfs(next, n);
			}
			else if (finish[next] == 0) {
				m = 0;
			}
		}
	}
	finish[start] = 1;
	sort[i++] = now;
}
int main()
{
	int N;
	scanf("%d", &N);
	while(scanf("%d %d", &from, &to) != EOF){
		link[from][to] = 1;
	}

	m = 1;
	for (int q = 1; q <= N; q++) {
		if (visit[q] == 0)
			dfs(q, N);
	}
	printf("%d\n", m);
	if (m == 1) {
		for (int k = N; k > 0; k--)
			printf("%d ", sort[k]);
	}
	return 0;
}