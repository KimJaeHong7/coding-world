#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int N, x, y, d, g;
int map[101][101];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };
vector<int> v;
int ans;

void make_dir() {
	for (int i = 0; i < g; i++) {
		for (int j = v.size() - 1; j >= 0; j--) {
			v.push_back((v[j] + 1) % 4);
		}
	}
}
void dragoncurve(int sx, int sy) {
	map[sx][sy] = 1;
	for (int i = 0; i < v.size(); i++) {
		sx += dx[v[i]];
		sy += dy[v[i]];
		if(sx>=0 && sy>=0 && sx<=100 && sy<=100)
			map[sx][sy] = 1;
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		v.clear();
		scanf("%d %d %d %d", &x, &y, &d, &g);
		v.push_back(d);
		make_dir();
		dragoncurve(y, x);
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1])
				ans++;
		}
	}
	printf("%d", ans);
	return 0;
}