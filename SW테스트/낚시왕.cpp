#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
priority_queue<int,vector<int>,greater<int>> shark[100];
vector<pair<int, int>> v[100][100];
vector<pair<int,int>> _size[100][100];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int r, c, s, d, z, m;
int ans;
void shark_move() {
	vector<pair<int, int>> temp[100][100];
	vector<pair<int,int>> temp_size[100][100];
	for (int i = 0; i < c; i++) {
		if (!shark[i].empty()) {
			while (!shark[i].empty()) {
				int dir = v[shark[i].top()][i][0].second;
				int k = v[shark[i].top()][i][0].first;
				int nx = shark[i].top();
				int ny = i;
				int h = nx;
				int d = ny;
				if (dir == 0 || dir == 1)
					k = k % ((r - 1) * 2);
				else
					k = k % ((c - 1) * 2);
				for (int a = 0; a < k; a++) {
					if (dir == 0 || dir == 1) {
						if (nx == 0) {
							dir = 1;
						}
						else if (nx == r - 1)
							dir = 0;
						nx += dx[dir];
					}
					else if (dir == 2 || dir == 3) {
						if (ny == 0) {
							dir = 2;
						}
						else if (ny == c - 1)
							dir = 3;
						ny += dy[dir];
					}
				}
				temp[nx][ny].push_back({ k, dir });
				temp_size[nx][ny].push_back({ _size[h][d][0].first,temp[nx][ny].size() });
				shark[i].pop();
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (temp[i][j].empty()) {
				continue;
			}
			v[i][j].clear();
			_size[i][j].clear();
			if (temp[i][j].size() == 1) {
				v[i][j] = temp[i][j];
				_size[i][j] = temp_size[i][j];
				shark[j].push(i);
			}
			else if (temp[i][j].size() > 1) {
				sort(temp_size[i][j].begin(), temp_size[i][j].end());
				int size = temp_size[i][j].back().first;
				int idx = temp_size[i][j].back().second-1;
				int dir = temp[i][j][idx].second;
				int k = temp[i][j][idx].first;
				v[i][j].push_back({ k, dir });
				_size[i][j].push_back({ size,0 });
				shark[j].push(i);
			}
		}
	}
}
void solution() {
	for (int i = 0; i < c; i++) {
		if (!shark[i].empty()) {
			ans = ans + _size[shark[i].top()][i][0].first;
			_size[shark[i].top()][i].clear();
			v[shark[i].top()][i].clear();
			shark[i].pop();
		}
		shark_move();
	}
}
int main() {
	int x, y;
	scanf("%d %d %d", &r, &c, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d %d %d", &x, &y, &s, &d, &z);
		shark[y-1].push(x-1);
		_size[x-1][y-1].push_back({ z,0 });
		v[x-1][y-1].push_back({ s,d - 1});
	}
	if(m!=0)
		solution();
	printf("%d", ans);
}