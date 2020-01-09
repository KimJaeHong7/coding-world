#include <stdio.h>
#include <iostream>

using namespace std;
int max1;
int map2[21][21];
void solution(int n,int dir, int map1[21][21], int cnt) {
	int temp = 0;
	int map[21][21];
	int num[21];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = map1[i][j];
		}
	}
	if (cnt > 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (max1 < map[i][j])
					max1 = map[i][j];
			}
		}
		return;
	}
	if (dir == 0) {
		for (int i = 0; i < n; i++) {
			temp = 0;
			for (int l = 0; l < 21; l++) {
				num[l] = 0;
			}
			for (int j = 0; j < n; j++) {
				int p = 1;
				if (map[j][i]==0) {
					continue;
				}
				while (1) {
					if (j + p >= n-1)
						break;
					if (map[j + p][i] > 0)
						break;
					p++;
				}
				if (j!=n-1 && map[j][i] == map[j + p][i]) {
					num[temp++] = map[j][i] + map[j + p][i];
					map[j + p][i] = 0;
				}
				else {
					num[temp++] = map[j][i];
					map[j][i] = 0;
				}
			}
			int m = 0;
			for (int k = 0; k < n; k++) {
				map[k][i] = num[m++];
			}
		}
	}
	else if (dir == 1) {
		for (int i = 0; i < n; i++) {
			temp = 0;
			for (int l = 0; l < 20; l++) {
				num[l] = 0;
			}
			for (int j = n-1; j >= 0; j--) {
				int p = 1;
				if (map[j][i]==0)
					continue;
				while (1) {
					if (j - p <= 0)
						break;
					if (map[j - p][i] > 0)
						break;
					p++;
				}
				if (j!=0 && map[j][i] == map[j - p][i]) {
					num[temp++] = map[j][i] + map[j - p][i];
					map[j - p][i] = 0;
				}
				else {
					num[temp++] = map[j][i];
					map[j][i] = 0;
				}
			}
			int m = 0;
			for (int k = n - 1; k >= 0; k--) {
				map[k][i] = num[m++];
			}
		}
	}
	else if (dir == 2) {
		for (int i = 0; i < n; i++) {
			temp = 0;
			for (int l = 0; l < 20; l++) {
				num[l] = 0;
			}
			for (int j = 0; j < n; j++) {
				int p = 1;
				if (map[i][j]==0)
					continue;
				while (1) {
					if (j + p >= n - 1)
						break;
					if (map[i][j+p] > 0)
						break;
					p++;
				}
				if (j != n - 1 && map[i][j] == map[i][j + p]) {
					num[temp++] = map[i][j] + map[i][j + p];
					map[i][j + p] = 0;
				}
				else {
					num[temp++] = map[i][j];
					map[i][j] = 0;
				}
			}
			int m = 0;
			for (int k = 0; k < n; k++) {
				map[i][k] = num[m++];
			}
		}
	}
	else if (dir == 3) {
		for (int i = 0; i < n; i++) {
			temp = 0;
			for (int l = 0; l < 20; l++) {
				num[l] = 0;
			}
			for (int j = n - 1; j >= 0; j--) {
				int p = 1;
				if (map[i][j]==0)
					continue;
				while (1) {
					if (j - p <= 0)
						break;
					if (map[i][j-p] > 0)
						break;
					p++;
				}
				if (j != 0 && map[i][j] == map[i][j-p]) {
					num[temp++] = map[i][j] + map[i][j - p];
					map[i][j - p] = 0;
				}
				else {
					num[temp++] = map[i][j];
					map[i][j] = 0;
				}
			}
			int m = 0;
			for (int k = n - 1; k >= 0; k--) {
				map[i][k] = num[m++];
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		solution(n, i, map, cnt + 1);
	}
}
int main() {
	int n;
	scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map2[i][j];
			}
		}
		for (int i = 0; i < 4; i++) {
			solution(n, i, map2, 1);
		}
		printf("%d\n", max1);
	return 0;
}