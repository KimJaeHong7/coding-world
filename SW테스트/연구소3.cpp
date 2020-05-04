#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int map[50][50];
int temp[50][50];
int visit[50][50];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<pair<int, int> > virus;
vector<pair<int, int> > virus1;
int cnt;
int num;
int ans = 987654321;
int flag;
void BFS() {
	int temp_num = num;
	flag = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = map[i][j];
			visit[i][j] = 0;
		}
	}
	queue<pair<int, int>> q;
	for (int i = 0; i < virus1.size(); i++) {
		int x = virus1[i].first;
		int y = virus1[i].second;
		q.push({ x,y });
		visit[x][y] = 1;
	}
	while (!q.empty()) {
		int size = q.size();
		if (temp_num == 0) {
			flag = 1;
			return;
		}
		cnt++;
		for (int i = 0; i < size; i++) {
			int a = q.front().first;
			int b = q.front().second;
			visit[a][b] = 1;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int nextX = a + dx[j];
				int nextY = b + dy[j];
				if (nextX >= 0 && nextX < N&& nextY >= 0 && nextY < N) {
					if (!visit[nextX][nextY]) {
						if (temp[nextX][nextY] == 0 || temp[nextX][nextY] == 2) {
							if (temp[nextX][nextY] == 0)
								temp_num--;
							visit[nextX][nextY] = 1;
							temp[nextX][nextY] = 2;
							q.push({ nextX,nextY });
						}
					}
				}
			}
		}
	}
}
void set_virus(int c, int k) {
	if (c == M) {
		BFS();
		if (flag) {
			if (cnt < ans)
				ans = cnt;
		}
		cnt = 0;
		return;
	}
	for (int i = 0; i < virus.size(); i++) {
		if (i <= k)
			continue;
		int x = virus[i].first;
		int y = virus[i].second;
		virus1.push_back({ x,y });
		set_virus(c + 1, i);
		virus1.pop_back();
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				virus.push_back({ i,j });
			}
			if (map[i][j] == 0)
				num++;
		}
	}
	set_virus(0, -1);
	if (ans != 987654321)
		printf("%d", ans);
	else
		printf("-1");
	return 0;
}