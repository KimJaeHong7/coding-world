#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;
int N, M;
int map[8][8];
int temp[8][8];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int cnt = 1234556777;
vector<pair<int, pair<int, int>>> cctv;
vector<pair<int, int>> di;
void c_one(int nx, int ny, int index);
void c_two(int nx, int ny, int index);
void c_three(int nx, int ny, int index);
void c_four(int nx, int ny, int index);
void c_five(int nx, int ny, int index);
void count() {
	int b = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (temp[i][j] == 0) {
				b++;
			}
		}
	}
	if (b < cnt)
		cnt = b;
}
void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp[i][j] = map[i][j];
		}
	}
}
void c_one(int nx, int ny, int index) {
	queue<pair<int, int>> q;
	queue<pair<int, int>> p;
	for (int i = 0; i < 4; i++) {
		q.push({ nx,ny });
		while (!q.empty()) {
			int a = q.front().first + dx[i];
			int b = q.front().second + dy[i];
			q.pop();
			if (temp[a][b] == 6 || a < 0 || b < 0 || a > N-1 || b > M-1)
				continue;
			else {
				q.push({ a,b });
				if (temp[a][b] == 0) {
					temp[a][b] = 9;
					p.push({ a,b });
				}
			}
		}
		if (index + 1 < cctv.size()) {
			if (cctv[index + 1].first == 1) {
				c_one(cctv[index + 1].second.first, cctv[index + 1].second.second, index + 1);
			}
			if (cctv[index + 1].first == 2) {
				c_two(cctv[index + 1].second.first, cctv[index + 1].second.second, index + 1);
			}
			if (cctv[index + 1].first == 3) {
				c_three(cctv[index + 1].second.first, cctv[index + 1].second.second, index + 1);
			}
			if (cctv[index + 1].first == 4) {
				c_four(cctv[index + 1].second.first, cctv[index + 1].second.second, index + 1);
			}
			if (cctv[index + 1].first == 5) {
				c_five(cctv[index + 1].second.first, cctv[index + 1].second.second, index + 1);
			}
		}
		else {
			count();
		}
		while (!p.empty()) {
			temp[p.front().first][p.front().second] = 0;
			p.pop();
		}
	}
}
void c_two(int nx, int ny, int index) {
	queue<pair<int, int>> q;
	queue<pair<int, int>> p;
	for (int j = 0; j < 2; j++) {
		if (j == 0) {
			for (int i = 0; i < 2; i++) {
				q.push({ nx,ny });
				while (!q.empty()) {
					int a = q.front().first + dx[i];
					int b = q.front().second + dy[i];
					q.pop();
					if (temp[a][b] == 6 || a < 0 || b < 0 || a > N - 1 || b > M - 1)
						continue;
					else {
						q.push({ a,b });
						if (temp[a][b] == 0) {
							temp[a][b] = 9;
							p.push({ a,b });
						}
					}
				}
			}
		}
		else {
			for (int i = 2; i < 4; i++) {
				q.push({ nx,ny });
				while (!q.empty()) {
					int a = q.front().first + dx[i];
					int b = q.front().second + dy[i];
					q.pop();
					if (temp[a][b] == 6 || a < 0 || b < 0 || a > N - 1 || b > M - 1)
						continue;
					else {
						q.push({ a,b });
						if (temp[a][b] == 0) {
							temp[a][b] = 9;
							p.push({ a,b });
						}
					}
				}
			}
		}
		if (index + 1 < cctv.size()) {
			if (cctv[index + 1].first == 1) {
				c_one(cctv[index + 1].second.first, cctv[index + 1].second.second, index + 1);
			}
			if (cctv[index + 1].first == 2) {
				c_two(cctv[index + 1].second.first, cctv[index + 1].second.second, index + 1);
			}
			if (cctv[index + 1].first == 3) {
				c_three(cctv[index + 1].second.first, cctv[index + 1].second.second, index + 1);
			}
			if (cctv[index + 1].first == 4) {
				c_four(cctv[index + 1].second.first, cctv[index + 1].second.second, index + 1);
			}
			if (cctv[index + 1].first == 5) {
				c_five(cctv[index + 1].second.first, cctv[index + 1].second.second, index + 1);
			}
		}
		else {
			count();
		}
		while (!p.empty()) {
			temp[p.front().first][p.front().second] = 0;
			p.pop();
		}
	}
}
void c_three(int nx, int ny, int index) {
	queue<pair<int, int>> q;
	queue<pair<int, int>> p;
	for (int j = 0; j < 4; j++) {
		if (j == 0) {
			for (int i = 0; i < 4; i++) {
				if (i == 0 || i == 2)
					continue;
				q.push({ nx,ny });
				while (!q.empty()) {
					int a = q.front().first + dx[i];
					int b = q.front().second + dy[i];
					q.pop();
					if (temp[a][b] == 6 || a < 0 || b < 0 || a > N - 1 || b > M - 1)
						continue;
					else {
						q.push({ a,b });
						if (temp[a][b] == 0) {
							temp[a][b] = 9;
							p.push({ a,b });
						}
					}
				}
			}
		}
		else if (j == 1) {
			for (int i = 0; i < 4; i++) {
				if (i == 1 || i == 2)
					continue;
				q.push({ nx,ny });
				while (!q.empty()) {
					int a = q.front().first + dx[i];
					int b = q.front().second + dy[i];
					q.pop();
					if (temp[a][b] == 6 || a < 0 || b < 0 || a > N - 1 || b > M - 1)
						continue;
					else {
						q.push({ a,b });
						if (temp[a][b] == 0) {
							temp[a][b] = 9;
							p.push({ a,b });
						}
					}
				}
			}
		}
		else if (j == 2) {
			for (int i = 0; i < 4; i++) {
				if (i == 1 || i == 3)
					continue;
				q.push({ nx,ny });
				while (!q.empty()) {
					int a = q.front().first + dx[i];
					int b = q.front().second + dy[i];
					q.pop();
					if (temp[a][b] == 6 || a < 0 || b < 0 || a > N - 1 || b > M - 1)
						continue;
					else {
						q.push({ a,b });
						if (temp[a][b] == 0) {
							temp[a][b] = 9;
							p.push({ a,b });
						}
					}
				}
			}
		}
		else if (j == 3) {
			for (int i = 0; i < 4; i++) {
				if (i == 0 || i == 3)
					continue;
				q.push({ nx,ny });
				while (!q.empty()) {
					int a = q.front().first + dx[i];
					int b = q.front().second + dy[i];
					q.pop();
					if (temp[a][b] == 6 || a < 0 || b < 0 || a > N - 1 || b > M - 1)
						continue;
					else {
						q.push({ a,b });
						if (temp[a][b] == 0) {
							temp[a][b] = 9;
							p.push({ a,b });
						}
					}
				}
			}
		}
		if (index + 1 < cctv.size()) {
			if (cctv[index + 1].first == 1) {
				c_one(cctv[index + 1].second.first, cctv[index + 1].second.second, index + 1);
			}
			if (cctv[index + 1].first == 2) {
				c_two(cctv[index + 1].second.first, cctv[index + 1].second.second, index + 1);
			}
			if (cctv[index + 1].first == 3) {
				c_three(cctv[index + 1].second.first, cctv[index + 1].second.second, index + 1);
			}
			if (cctv[index + 1].first == 4) {
				c_four(cctv[index + 1].second.first, cctv[index + 1].second.second, index + 1);
			}
			if (cctv[index + 1].first == 5) {
				c_five(cctv[index + 1].second.first, cctv[index + 1].second.second, index + 1);
			}
		}
		else {
			count();
		}
		while (!p.empty()) {
			temp[p.front().first][p.front().second] = 0;
			p.pop();
		}
	}
}
void c_four(int nx, int ny, int index) {
	queue<pair<int, int>> q;
	queue<pair<int, int>> p;
	for (int j = 0; j < 4; j++) {
		if (j == 0) {
			for (int i = 0; i < 4; i++) {
				if (i == 0)
					continue;
				q.push({ nx,ny });
				while (!q.empty()) {
					int a = q.front().first + dx[i];
					int b = q.front().second + dy[i];
					q.pop();
					if (temp[a][b] == 6 || a < 0 || b < 0 || a > N - 1 || b > M - 1)
						continue;
					else {
						q.push({ a,b });
						if (temp[a][b] == 0) {
							temp[a][b] = 9;
							p.push({ a,b });
						}
					}
				}
			}
		}
		else if (j == 1) {
			for (int i = 0; i < 4; i++) {
				if (i == 1)
					continue;
				q.push({ nx,ny });
				while (!q.empty()) {
					int a = q.front().first + dx[i];
					int b = q.front().second + dy[i];
					q.pop();
					if (temp[a][b] == 6 || a < 0 || b < 0 || a > N - 1 || b > M - 1)
						continue;
					else {
						q.push({ a,b });
						if (temp[a][b] == 0) {
							temp[a][b] = 9;
							p.push({ a,b });
						}
					}
				}
			}
		}
		else if (j == 2) {
			for (int i = 0; i < 4; i++) {
				if (i == 2)
					continue;
				q.push({ nx,ny });
				while (!q.empty()) {
					int a = q.front().first + dx[i];
					int b = q.front().second + dy[i];
					q.pop();
					if (temp[a][b] == 6 || a < 0 || b < 0 || a > N - 1 || b > M - 1)
						continue;
					else {
						q.push({ a,b });
						if (temp[a][b] == 0) {
							temp[a][b] = 9;
							p.push({ a,b });
						}
					}
				}
			}
		}
		else if (j == 3) {
			for (int i = 0; i < 4; i++) {
				if (i == 3)
					continue;
				q.push({ nx,ny });
				while (!q.empty()) {
					int a = q.front().first + dx[i];
					int b = q.front().second + dy[i];
					q.pop();
					if (temp[a][b] == 6 || a < 0 || b < 0 || a > N - 1 || b > M - 1)
						continue;
					else {
						q.push({ a,b });
						if (temp[a][b] == 0) {
							temp[a][b] = 9;
							p.push({ a,b });
						}
					}
				}
			}
		}
		if (index + 1 < cctv.size()) {
			if (cctv[index + 1].first == 1) {
				c_one(cctv[index + 1].second.first, cctv[index + 1].second.second, index + 1);
			}
			if (cctv[index + 1].first == 2) {
				c_two(cctv[index + 1].second.first, cctv[index + 1].second.second, index + 1);
			}
			if (cctv[index + 1].first == 3) {
				c_three(cctv[index + 1].second.first, cctv[index + 1].second.second, index + 1);
			}
			if (cctv[index + 1].first == 4) {
				c_four(cctv[index + 1].second.first, cctv[index + 1].second.second, index + 1);
			}
			if (cctv[index + 1].first == 5) {
				c_five(cctv[index + 1].second.first, cctv[index + 1].second.second, index + 1);
			}
		}
		else {
			count();
		}
		while (!p.empty()) {
			temp[p.front().first][p.front().second] = 0;
			p.pop();
		}
	}
}
void c_five(int nx, int ny, int index) {
	queue<pair<int, int>> q;
	for (int i = 0; i < 4; i++) {
		q.push({ nx,ny });
		while (!q.empty()) {
			int a = q.front().first + dx[i];
			int b = q.front().second + dy[i];
			q.pop();
			if (temp[a][b] == 6 || a < 0 || b < 0 || a > N - 1 || b > M - 1)
				continue;
			else {
				q.push({ a,b });
				if (temp[a][b] == 0)
					temp[a][b] = 9;
			}
		}
	}
	if (index + 1 < cctv.size()) {
		if (cctv[index + 1].first == 1) {
			c_one(cctv[index + 1].second.first, cctv[index + 1].second.second, index + 1);
		}
		if (cctv[index + 1].first == 2) {
			c_two(cctv[index + 1].second.first, cctv[index + 1].second.second, index + 1);
		}
		if (cctv[index + 1].first == 3) {
			c_three(cctv[index + 1].second.first, cctv[index + 1].second.second, index + 1);
		}
		if (cctv[index + 1].first == 4) {
			c_four(cctv[index + 1].second.first, cctv[index + 1].second.second, index + 1);
		}
		if (cctv[index + 1].first == 5) {
			c_five(cctv[index + 1].second.first, cctv[index + 1].second.second, index + 1);
		}
	}
	else {
		count();
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] != 0 && map[i][j] != 6)
				cctv.push_back({ map[i][j],{i,j} });
		}
	}
	init();
	if (!cctv.empty()) {
		if (cctv[0].first == 1)
			c_one(cctv[0].second.first, cctv[0].second.second, 0);
		else if (cctv[0].first == 2)
			c_two(cctv[0].second.first, cctv[0].second.second, 0);
		else if (cctv[0].first == 3)
			c_three(cctv[0].second.first, cctv[0].second.second, 0);
		else if (cctv[0].first == 4)
			c_four(cctv[0].second.first, cctv[0].second.second, 0);
		else if (cctv[0].first == 5)
			c_five(cctv[0].second.first, cctv[0].second.second, 0);
		printf("%d", cnt);
	}
	else {
		count();
		printf("%d", cnt);
	}
	return 0;
}