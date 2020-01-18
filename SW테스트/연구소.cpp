#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
int N, M, max_;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<int, int>> q;
void virus(int map[8][8]) {
	int k = 0;
	queue<pair<int, int>> temp;
	temp = q;
	while (!temp.empty()) {
		int nx = temp.front().first;
		int ny = temp.front().second;
		temp.pop();
		for (int i = 0; i < 4; i++) {
			nx += dx[i];
			ny += dy[i];
			if (nx<0 || ny<0 || nx>N - 1 || ny>M - 1) {
				nx -= dx[i];
				ny -= dy[i];
				continue;
			}
			if (map[nx][ny] == 0) {
				temp.push({ nx,ny });
				map[nx][ny] = 2;
			}
			nx -= dx[i];
			ny -= dy[i];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0)
				k++;
		}
	}
	if (k > max_)
		max_ = k;
}
void wall(int cnt, int map[8][8]) {
	int temp[8][8];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			temp[i][j] = map[i][j];
	}
	if (cnt > 3) {
		virus(temp);
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (temp[i][j] == 0) {
				temp[i][j] = 1;
				wall(cnt + 1, temp);
				temp[i][j] = 0;
			}
		}
	}

}
int main() {
	int map[8][8];
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2)
				q.push({ i,j });
		}
	}
	wall(1, map);
	printf("%d", max_);
	return 0;
}