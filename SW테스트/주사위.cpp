#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int N, M, nx, ny, k;
int map[20][20];
int dice[6];
int bot = 5;
int kx[4] = { 0,0,-1,1 };
int ky[4] = { 1,-1,0,0 };
void move_dice(int dir) {
	if (dir == 1) {
		int temp = dice[0];
		dice[0] = dice[3];
		dice[3] = dice[5];
		dice[5] = dice[2];
		dice[2] = temp;
	}
	else if (dir == 2) {
		int temp = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[5];
		dice[5] = dice[3];
		dice[3] = temp;
	}
	else if (dir == 3) {
		int temp = dice[0];
		dice[0] = dice[4];
		dice[4] = dice[5];
		dice[5] = dice[1];
		dice[1] = temp;
	}
	else {
		int temp = dice[0];
		dice[0] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[4];
		dice[4] = temp;
	}
}
void solution(int dir) {
	nx += kx[dir - 1];
	ny += ky[dir - 1];
	if (nx<0 || nx>N - 1 || ny<0 || ny>M - 1) {
		nx -= kx[dir - 1];
		ny -= ky[dir - 1];
		return;
	}
	move_dice(dir);
	if (map[nx][ny] == 0) {
		map[nx][ny] = dice[5];
	}
	else {
		dice[5] = map[nx][ny];
		map[nx][ny] = 0;
	}
	printf("%d\n", dice[0]);
}
int main() {//1 悼率, 2 辑率, 3 合率, 4 巢率
	scanf("%d %d %d %d %d",&N, &M, &nx, &ny, &k);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < k; i++) {
		int num;
		scanf("%d", &num);
		solution(num);
	}
	return 0;
}