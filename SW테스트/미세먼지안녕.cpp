#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int map[51][51];
int r, c, t;
int ux, uy, dx, dy;
vector<pair<int,int>> v;
int dir_x[4] = { -1,1,0,0 };
int dir_y[4] = { 0,0,-1,1 };
void find_() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] > 0)
				v.push_back({ i,j });
		}
	}
}
void plus_() {
	int temp1[50][50];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			temp1[i][j] = map[i][j];
	}
	int temp = v.size();
	for (int i = 0; i < temp; i++) {
		for (int j = 0; j < 4; j++) {
			int a = v[i].first + dir_x[j];
			int b = v[i].second + dir_y[j];
			int cnt = temp1[v[i].first][v[i].second] / 5;
			if (a >= 0 && b >= 0 && a < r&&b < c) {
				if (map[a][b] >= 0) {
					map[a][b] += cnt;
					map[v[i].first][v[i].second] -= cnt;
				}
			}
		}
	}
	v.clear();
}
void clear_() {
	int temp[50][50];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			temp[i][j] = map[i][j];
	}
	for (int i = uy + 1; i < c-1; i++) {
		temp[ux][i + 1] = map[ux][i];
		if(i == uy+1)
			temp[ux][i] = 0;
	}
	for (int i = ux; i > 0; i--) {
		temp[i - 1][c - 1] = map[i][c - 1];
	}
	for (int i = c - 1; i > 0; i--) {
		temp[0][i - 1] = map[0][i];
	}
	for (int i = 0; i < ux; i++) {
		if (i + 1 == ux)
			continue;
		temp[i + 1][0] = map[i][0];
	}

	for (int i = dy + 1; i < c - 1; i++) {
		temp[dx][i + 1] = map[dx][i];
		if(i == dy+1)
			temp[dx][i] = 0;
	}
	for (int i = dx; i < r; i++) {
		temp[i + 1][c - 1] = map[i][c - 1];
	}
	for (int i = c - 1; i > 0; i--) {
		temp[r-1][i - 1] = map[r-1][i];
	}
	for (int i = r-1; i > dx; i--) {
		if (i - 1 == dx)
			continue;
		temp[i - 1][0] = map[i][0];
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			map[i][j] = temp[i][j];
	}
}
int main() {
	int k = 0;
	scanf("%d %d %d", &r, &c, &t);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%d", &map[i][j]);
			if (k == 0 && map[i][j] == -1) {
				ux = i;
				uy = j;
				k = 1;
			}
			else if (k == 1 && map[i][j] == -1) {
				dx = i;
				dy = j;
			}
		}
	}
	for (int i = 0; i < t; i++) {
		v.clear();
		find_();
		plus_();
		clear_();
	}
	find_();
	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		ans += map[v[i].first][v[i].second];
	}
	printf("%d", ans);
	return 0;
}