#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int N, L, R;
int map[51][51];
int visit[51][51];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int sum, ans, cnt;
int flag;
vector<pair<int, int>> v;
void DFS(int r, int c) {
	v.push_back({ r,c });
	sum += map[r][c];
	cnt++;
	visit[r][c] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = r + dx[i];
		int ny = c + dy[i];
		if (nx <= 0 || nx > N || ny <= 0 || ny > N)
			continue;
		if (visit[nx][ny]==0 && abs(map[r][c] - map[nx][ny]) >= L && abs(map[r][c] - map[nx][ny]) <= R) {
			visit[nx][ny] = 1;
			DFS(nx,ny);
		}
	}
}
void visit_Clear() {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			visit[i][j] = 0;
		}
	}
}
int main() {
	scanf("%d %d %d", &N, &L, &R);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	while (1) {
		flag = 0;
		visit_Clear();
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (visit[i][j] != 0)
					continue;
				DFS(i, j);
				if (cnt != 1) {
					flag = 1;
					for (int k = 0; k < v.size(); k++) {
						int a = v[k].first;
						int b = v[k].second;
						map[a][b] = sum / cnt;
					}
				}
				sum = 0;
				cnt = 0;
				v.clear();
			}
		}
		if (flag == 1)
			ans++;
		else
			break;
	}
	printf("%d", ans);
}