#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N;
int map[21][21];
int visit[21][21];
int sum[6];
int min_ = 987654321;
vector<int> v[21];
int solution(int x, int y, int d1, int d2) {
	for (int i = 1; i <= N; i++) {
		v[i].clear();
		for (int j = 1; j <= N; j++)
			visit[i][j] = 0;
	}
	for (int i = 0; i <= 5; i++)
		sum[i] = 0;

	if ((x + d1 + d2) > N || (y - d1)<1 || (y + d2) > N)
		return -1;
	for (int i = 0; i <= d1; i++) {
		if (visit[x + i][y - i])
			continue;
		visit[x + i][y - i] = 5;
		sum[5] += map[x + i][y - i];
		v[x + i].push_back(y - i);
	}
	for (int i = 0; i <= d2; i++) {
		if (visit[x + i][y + i])
			continue;
		visit[x + i][y + i] = 5;
		sum[5] += map[x + i][y + i];
		v[x + i].push_back(y + i);
	}
	for (int i = 0; i <= d2; i++) {
		if (visit[x + d1 + i][y - d1 + i])
			continue;
		visit[x + d1 + i][y - d1 + i] = 5;
		sum[5] += map[x + d1 + i][y - d1 + i];
		v[x + d1 + i].push_back(y - d1 + i);
	}
	for (int i = 0; i <= d1; i++) {
		if (visit[x + d2 + i][y + d2 - i])
			continue;
		visit[x + d2 + i][y + d2 - i] = 5;
		sum[5] += map[x + d2 + i][y + d2 - i];
		v[x + d2 + i].push_back(y + d2 - i);
	}
	for (int i = 1; i <= N; i++) {
		if (!v[i].empty()) {
			if (v[i].size() > 1) {
				sort(v[i].begin(), v[i].end());
				int y1 = v[i][0];
				int y2 = v[i][1];
				for (int j = y1 + 1; j < y2; j++) {
					visit[i][j] = 5;
					sum[5] += map[i][j];
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visit[i][j])
				continue;
			if (i >= 1 && i < (x + d1) && j >= 1 && j <= y) {
				visit[i][j] = 1;
				sum[1] += map[i][j];
			}
			else if (i >= 1 && i <= (x + d2) && j > y && j <= N) {
				visit[i][j] = 2;
				sum[2] += map[i][j];
			}
			else if (i >= (x + d1) && i <= N && j >= 1 && j < (y - d1 + d2)) {
				visit[i][j] = 3;
				sum[3] += map[i][j];
			}
			else if (i > (x + d2) && i <= N && j >= (y - d1 + d2) && j <= N) {
				visit[i][j] = 4;
				sum[4] += map[i][j];
			}
		}
	}
	sort(sum + 1, sum + 6);
	return sum[5] - sum[1];
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 1; i <= N-2; i++) {
		for (int j = 2; j <= N-1 ; j++) {
			for (int k = 1; k <= N-2 ; k++) {
				for (int p = 1; p <= N-2 ; p++) {
					if (solution(i, j, k, p) == -1)
						continue;
					else {
						if (solution(i, j, k, p) < min_)
							min_ = solution(i, j, k, p);
					}
				}
			}
		}
	}
	printf("%d", min_);
	return 0;
}