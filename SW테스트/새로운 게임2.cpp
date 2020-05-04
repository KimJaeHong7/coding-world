#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int map[12][12];
int N, k;
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,1,-1,0,0 };
stack<int> cnt[12][12];
int ans;
vector<pair<pair<int, int>, int >> horse;
void solution(int count) {
	if (count > 1000) {
		ans = -1;
		return;
	}
	else {
		for (int i = 0; i < k; i++) {
			int x = horse[i].first.first;
			int y = horse[i].first.second;
			int dir = horse[i].second;
			if (cnt[x][y].top() == i) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (map[nx][ny] == 2 || nx < 0 || ny < 0 || nx >= N || ny >= N) {
					if (dir == 1 || dir == 2) {
						dir = 3 - dir;
						nx = x + dx[dir];
						ny = y + dy[dir];
					}
					else {
						dir = 7 - dir;
						nx = x + dx[dir];
						ny = y + dy[dir];
					}
					if (map[nx][ny] == 2 || nx < 0 || ny < 0 || nx >= N || ny >= N) {
						horse[i].second = dir;
						continue;
					}
					else if(map[nx][ny]==0||map[nx][ny]==1){
						horse[i].first.first = nx;
						horse[i].first.second = ny;
						horse[i].second = dir;
						cnt[nx][ny].push(i);
						cnt[x][y].pop();
					}
				}
				else if (map[nx][ny] == 0 || map[nx][ny] == 1) {
					horse[i].first.first = nx;
					horse[i].first.second = ny;
					cnt[nx][ny].push(i);
					cnt[x][y].pop();
				}
			}
			else {
				vector<int> temp;
				temp.clear();
				while (cnt[x][y].top() != i) {
					temp.push_back(cnt[x][y].top());
					cnt[x][y].pop();
				}
				temp.push_back(cnt[x][y].top());
				cnt[x][y].pop();
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N || map[nx][ny] == 2) {
					if (dir == 1 || dir == 2) {
						dir = 3 - dir;
						nx = x + dx[dir];
						ny = y + dy[dir];
					}
					else {
						dir = 7 - dir;
						nx = x + dx[dir];
						ny = y + dy[dir];
					}
					if (map[nx][ny] == 2 || nx < 0 || ny < 0 || nx >= N || ny >= N) {
						horse[i].second = dir;
						for (int j = temp.size() - 1; j >= 0; j--) {
							cnt[x][y].push(temp[j]);
						}
						continue;
					}
					else {
						if (map[nx][ny] == 0) {
							for (int j = temp.size() - 1; j >= 0; j--) {
								horse[temp[j]].first.first = nx;
								horse[temp[j]].first.second = ny;
								horse[i].second = dir;
								cnt[nx][ny].push(temp[j]);
							}
						}
						else if (map[nx][ny] == 1) {
							for (int j = 0; j < temp.size(); j++) {
								horse[temp[j]].first.first = nx;
								horse[temp[j]].first.second = ny;
								horse[i].second = dir;
								cnt[nx][ny].push(temp[j]);
							}
						}
					}
				}
				else {
					if (map[nx][ny] == 0) {
						for (int j = temp.size() - 1; j >= 0; j--) {
							horse[temp[j]].first.first = nx;
							horse[temp[j]].first.second = ny;
							cnt[nx][ny].push(temp[j]);
						}
					}
					else if (map[nx][ny] == 1) {
						for (int j = 0; j < temp.size(); j++) {
							horse[temp[j]].first.first = nx;
							horse[temp[j]].first.second = ny;
							cnt[nx][ny].push(temp[j]);
						}
					}
				}
			}
			for (int a = 0; a < N; a++) {
				for (int b = 0; b < N; b++) {
					if (!cnt[a][b].empty()) {
						if (cnt[a][b].size() >= 4) {
							ans = count;
							return;
						}
					}
				}
			}
		}
	}
	solution(count + 1);
}
int main() {
	scanf("%d %d", &N, &k);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);
	}
	for (int i = 0; i < k; i++) {
		int x, y, dir;
		scanf("%d %d %d", &x, &y, &dir);
		horse.push_back({ {x-1,y-1},dir });
		cnt[x-1][y-1].push(i);
	}
	solution(1);
	printf("%d", ans);
	return 0;
}