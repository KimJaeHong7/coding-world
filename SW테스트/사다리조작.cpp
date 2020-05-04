#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;
int N, M, H;
int map[33][13];
int edge[33][13];
int visit[33][13];
int ans = 9999;
int check(int nx, int ny, int num) {
	while (1) {
		ny += edge[nx][ny];
		nx += 1;
		if (nx > H)
			break;
	}
	if (ny == num) {
		return 1;
	}
	else {
		return 0;
	}
}
void make_edge(int idx, int row, int cnt) {
	int flag = 0;
	for (int i = 1; i <= N; i++) {
		if (!check(1, i, i)) {
			flag = 0;
			break;
		}
		else {
			flag = 1;
		}
	}
	if (flag) {
		if (ans > cnt)
			ans = cnt;
		return;
	}
	else {
		if (cnt + 1 == 4)
			return;
		for (int i = idx; i <= H; i++) {
			for (int j = row; j < N; j++) {
				if (edge[i][j - 1] == 1 || edge[i][j + 1] != 0 || edge[i][j] != 0)
					continue;
				else {
					edge[i][j] = 1;
					edge[i][j + 1] = -1;
					if (j + 2 > N - 1) {
						make_edge(i + 1, 1, cnt + 1);
					}
					else {
						make_edge(i, j + 2, cnt + 1);
					}
					edge[i][j] = 0;
					edge[i][j + 1] = 0;
				}
			}
			row = 1;
		}
	}
}
int main() {
	scanf("%d %d %d", &N, &M, &H);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		edge[a][b] = 1;
		edge[a][b + 1] = -1;
	}
	make_edge(1, 1, 0);
	if (ans > 3)
		printf("-1");
	else
		printf("%d", ans);
	return 0;
}