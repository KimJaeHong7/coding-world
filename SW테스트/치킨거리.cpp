#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int map[51][51];
int N, M;
int ans = 999999;
vector<pair<int, int>> house;
vector<pair<int, int>> chic;
vector<pair<int, int>> chic_temp;
int dist(pair<int, int> r, pair<int, int> c) {
	return abs(r.first - c.first) + abs(r.second - c.second);
}
void chicken_dist() {
	int sum = 0;
	for (int i = 0; i < house.size(); i++) {
		int min = 1000000;
		for (int j = 0; j < chic_temp.size(); j++) {
			int temp = dist(house[i], chic_temp[j]);
			if (min > temp)
				min = temp;
		}
		sum += min;
	}
	if (ans > sum)
		ans = sum;
}
void set_chicken(int cnt, int k) {
	if (cnt > M)
		return;
	for (int i = 0; i < chic.size(); i++) {
		if (k >= i)
			continue;
		chic_temp.push_back(chic[i]);
		chicken_dist();
		set_chicken(cnt + 1, i);
		chic_temp.pop_back();
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				house.push_back({ i,j });
			}
			else if (map[i][j] == 2) {
				chic.push_back({ i,j });
			}
		}
	}
	set_chicken(1, -1);
	printf("%d", ans);
	return 0;
}