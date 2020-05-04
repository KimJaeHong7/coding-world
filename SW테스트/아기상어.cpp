#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int map[20][20];
int visit[20][20];
int N;
int dx[4] = { -1, 0,1,0 };
int dy[4] = { 0, -1,0,1 };
queue < pair<pair<int, int>, int>> q;

void visit_init() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			visit[i][j] = 0;
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) {
				q.push({ {i,j},2 });
				map[i][j] = 0;
			}
		}
	}
	int cnt = 0;
	int ans = 0;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int size = q.front().second;
		q.pop();
		visit_init();
		visit[x][y] = 1;
		queue<pair<pair<int, int>, int>> temp;
		temp.push({ {x,y },0 });
		while (!temp.empty()) {
			int k = temp.size();
			priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> fish;
			for (int j = 0; j < k; j++) {
				int nx = temp.front().first.first;
				int ny = temp.front().first.second;
				int nt = temp.front().second;
				temp.pop();

				for (int i = 0; i < 4; i++) {
					int a = nx + dx[i];
					int b = ny + dy[i];

					if (a >= 0 && b >= 0 && a < N&&b < N) {
						if (!visit[a][b])
						{
							if (map[a][b] <= size)
							{
								temp.push({ {a,b},nt + 1 });
								visit[a][b] = 1;
								if (1 <= map[a][b] && map[a][b] < size)
									fish.push({ { a, b }, nt + 1 });
							}
						}
					}
				}
			}

			if (!fish.empty()) {
				cnt++;
				if (cnt == size) {
					q.push({ {fish.top().first},size + 1 });
					cnt = 0;
				}
				else {
					q.push({ {fish.top().first},size });
				}
				map[fish.top().first.first][fish.top().first.second] = 0;
				ans += fish.top().second;
				break;
			}
		}
	}
	printf("%d", ans);
	return 0;
}