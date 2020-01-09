#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int map[102][102];
vector<pair<int, int>> body;
vector<pair<int, char>> v;
pair<int, int> head;
pair<int, int> tail;
int move_t;
int n;
void solution() {
	int dx = 0;
	int dy = 1;
	while (1) {
		move_t++;
		head.first += dx;
		head.second += dy;
		if (map[head.first][head.second] == 2)
			break;
		if (head.first <= 0 || head.second <= 0 || head.first > n || head.second > n)
			break;
		body.push_back(head);
		if (map[head.first][head.second] != 1) {//사과가 없을 떄 꼬리 처리
			map[tail.first][tail.second] = 0;
			map[head.first][head.second] = 2;
			body.erase(body.begin());
			tail.first = body.begin()->first;
			tail.second = body.begin()->second;
		}
		else if(map[head.first][head.second]==1) {
			map[head.first][head.second] == 2;
		}
		if (!v.empty()) {
			if (move_t == v.begin()->first) {
				if (dx == 0 && dy == 1) {
					if (v.begin()->second == 'L') {
						dx = -1;
						dy = 0;
					}
					else {
						dx = 1;
						dy = 0;
					}
				}
				else if (dx == 0 && dy == -1) {
					if (v.begin()->second == 'L') {
						dx = 1;
						dy = 0;
					}
					else {
						dx = -1;
						dy = 0;
					}
				}
				else if (dx == 1 && dy == 0) {
					if (v.begin()->second == 'L') {
						dx = 0;
						dy = 1;
					}
					else {
						dx = 0;
						dy = -1;
					}
				}
				else {
					if (v.begin()->second == 'L') {
						dx = 0;
						dy = -1;
					}
					else {
						dx = 0;
						dy = 1;
					}
				}
				v.erase(v.begin());
			}
		}
	}
}
int main() {
	int k, inf;
	head.first = 1;
	head.second = 1;
	tail.first = 1;
	tail.second = 1;
	body.push_back({ 1,1 });
	scanf("%d", &n);
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int dx, dy;
		scanf("%d %d", &dx, &dy);
		map[dx][dy] = 1;
	}
	scanf("%d", &inf);
	for (int i = 0; i < inf; i++) {
		int a;
		char b;
		scanf("%d %c", &a, &b);
		v.push_back({ a ,b });
	}
	solution();
	printf("%d\n", move_t);
}