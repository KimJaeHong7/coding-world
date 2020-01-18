#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

int N, L, cnt;
int map[100][100];
int visit[100][100];
void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			visit[i][j] = 0;
	}
}
void search(int nx, int ny) {
	int a = nx;
	int b = ny;
	int temp[100][100];
	int k = 0;
	int flag = 0;
	int z = 1;
	int cflag = 0;
	int m = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			temp[i][j] = map[i][j];
	}
	//가로방향
	if (ny == 0) {
		for (int i = ny + 1; i < N; i++) {
			flag = 0;
			if (cflag == 1) {
				if (m < L - 1) {
					m++;
					continue;
				}
				else {
					cflag = 0;
					m = 0;
				}
			}
			if (temp[nx][i] == temp[nx][ny]) {
				k++;
				z++;
				ny = i;
				continue;
			}
			else if (temp[nx][i] < temp[nx][ny]) {
				z = 1;
				if (temp[nx][i] + 1 == temp[nx][ny]) {
					for (int j = 0; j < L; j++) {
						if (temp[nx][i] == temp[nx][i + j] && !visit[nx][i] && !visit[nx][i+j]) {
							flag = 1;
						}
						else {
							flag = 0;
							break;
						}
					}
					if (flag) {
						for (int j = 0; j < L; j++) {
							visit[nx][i + j] = 1;
						}
						k = k + L;
						ny = ny + L;
						cflag = 1;
					}
					else {
						break;
					}
				}
				else {
					break;
				}
			}
			else {
				int c = 0;
				for (int j = 1; j <= L; j++) {
					if (i - j < 0) {
						c = 1;
						break;
					}
					if (visit[nx][i - j]) {
						c = 1;
						break;
					}
				}
				if (z >= L && !c) {
					k++;
					ny = i;
					z = 1;
				}
				else {
					break;
				}
			}
		}
		if (k == N - 1) {
			cnt++;
		}
	}
	init();
	k = 0;
	cflag = 0;
	flag = 0;
	m = 0;
	z = 1;
	//세로방향
	if (nx == 0) {
		for (int i = nx + 1; i < N; i++) {
			flag = 0;
			if (cflag == 1) {
				if (m < L - 1) {
					m++;
					continue;
				}
				else {
					cflag = 0;
					m = 0;
				}
			}
			if (temp[i][b] == temp[nx][b]) {
				k++;
				z++;
				nx = i;
				continue;
			}
			else if (temp[i][b] < temp[nx][b]) {
				z = 1;
				if (temp[i][b] + 1 == temp[nx][b]) {
					for (int j = 0; j < L; j++) {
						if (temp[i][b] == temp[i + j][b] && !visit[i][b] && !visit[i + j][b]) {
							flag = 1;
						}
						else {
							flag = 0;
							break;
						}
					}
					if (flag) {
						for (int j = 0; j < L; j++) {
							visit[i + j][b] = 1;
						}
						k = k + L;
						nx = nx + L;
						cflag = 1;
					}
					else {
						break;
					}
				}
				else
					break;
			}
			else {
				int c = 0;
				for (int j = 1; j <= L; j++) {
					if (i - j < 0) {
						c = 1;
						break;
					}
					if (visit[i-j][b]) {
						c = 1;
						break;
					}
				}
				if (z >= L && !c) {
					k++;
					nx = i;
					z = 1;
				}
				else {
					break;
				}
			}
		}
		if (k == N - 1) {
			cnt++;
		}
		init();
	}
}
int main() {
	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			search(0, i);
			continue;
		}
		search(0, i);
		search(i, 0);
	}
	printf("%d", cnt);
	return 0;
}