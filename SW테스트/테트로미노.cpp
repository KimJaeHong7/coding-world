#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int N, M, max_;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int map[501][501];
int visit[501][501];
void shape(int nx, int ny, int cnt, int sum) {
	if (cnt == 3) {
		if (max_ < sum)
			max_ = sum;
		return;
	}
	for (int i = 0; i < 4; i++) {
		nx += dx[i];
		ny += dy[i];
		if (visit[nx][ny] == 1 || nx < 0 || ny < 0 || nx > N-1 || ny > M-1) {
			nx -= dx[i];
			ny -= dy[i];
			continue;
		}
		visit[nx][ny] = 1;
		sum += map[nx][ny];
		shape(nx, ny, cnt + 1, sum);
		sum -= map[nx][ny];
		visit[nx][ny] = 0;
		nx -= dx[i];
		ny -= dy[i];
	}
}
void shape1(int nx, int ny, int sum) {//ぬ
	if (nx + 1 > N || ny - 1 < 0 || ny + 1 > M)
		return;
	sum += (map[nx][ny - 1] + map[nx][ny + 1] + map[nx + 1][ny]);
	if (max_ < sum)
		max_ = sum;
}
void shape2(int nx, int ny, int sum) {//で
	if (nx - 1 < 0 || ny - 1 < 0 || ny + 1 > M)
		return;
	sum += (map[nx][ny - 1] + map[nx][ny + 1] + map[nx - 1][ny]);
	if (max_ < sum)
		max_ = sum;
}
void shape3(int nx, int ny, int sum) {//た
	if (nx - 1 < 0 || nx + 1 > N || ny + 1 > M)
		return;
	sum += (map[nx - 1][ny] + map[nx][ny + 1] + map[nx + 1][ny]);
	if (max_ < sum)
		max_ = sum;
}
void shape4(int nx, int ny, int sum) {//っ
	if (nx - 1 < 0 || nx + 1 > N || ny - 1 < 0)
		return;
	sum += (map[nx][ny - 1] + map[nx - 1][ny] + map[nx + 1][ny]);
	if (max_ < sum)
		max_ = sum;
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			shape1(i, j, map[i][j]);
			shape2(i, j, map[i][j]);
			shape3(i, j, map[i][j]);
			shape4(i, j, map[i][j]);
			visit[i][j] = 1;
			shape(i, j, 0, map[i][j]);
			visit[i][j] = 0;
		}
	}
	printf("%d", max_);
	return 0;
}