#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int A[101][101];
int r, c, k;
int r_cnt, c_cnt;
void r_init(int m) {
	for (int i = 1; i <= 100; i++) {
		A[m][i] = 0;
	}
}
void c_init(int m) {
	for (int i = 1; i <= 100; i++) {
		A[i][m] = 0;
	}
}
struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.first > b.first)
			return true;
		else if (a.first == b.first && a.second > b.second)
			return true;
		return false;
	}
};
void r_sort() {
	int p = c_cnt;
	for (int i = 1; i <= r_cnt; i++) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> temp;
		int cnt = 0;
		int num = 0;
		int flag = 0;
		sort(A[i] + 1, A[i] + p + 1);
		for (int j = 1; j <= p; j++) {
			int temp1 = A[i][j];
			if (temp1 == 0)
				continue;
			if (!flag) {
				flag = 1;
				num = A[i][j];
				cnt = 1;
				if (j == p)
					temp.push({ cnt,num });
				continue;
			}
			if (temp1 == num) {
				cnt++;
			}
			else {
				temp.push({ cnt,num });
				num = temp1;
				cnt = 1;
			}
			if (j == p)
				temp.push({ cnt,num });
		}
		r_init(i);
		int temp_c = 2;
		while (!temp.empty()) {
			int temp_cnt = temp.top().first;
			int temp_num = temp.top().second;
			temp.pop();
			if (temp_c - 1 <= 100)
				A[i][temp_c - 1] = temp_num;
			else
				break;
			if (temp_c <= 100)
				A[i][temp_c] = temp_cnt;
			else
				break;
			temp_c += 2;
		}
		if(c_cnt<temp_c-2)
			c_cnt = temp_c-2;
	}
}
void c_sort() {
	int p = r_cnt;
	for (int i = 1; i <= c_cnt; i++) {
		int temp_A[101];
		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> temp;
		int cnt = 0;
		int num = 0;
		int flag = 0;
		for (int b = 1; b <= p; b++) {
			temp_A[b] = A[b][i];
		}
		sort(temp_A + 1, temp_A + p + 1);
		for (int j = 1; j <= p; j++) {
			int temp1 = temp_A[j];
			if (temp1 == 0)
				continue;
			if (!flag) {
				flag = 1;
				num = temp_A[j];
				cnt = 1;
				if (j == p)
					temp.push({ cnt,num });
				continue;
			}
			if (temp1 == num) {
				cnt++;
			}
			else {
				temp.push({ cnt,num });
				num = temp1;
				cnt = 1;
			}
			if (j == p)
				temp.push({ cnt,num });
		}
		int temp_r = 2;
		c_init(i);
		while (!temp.empty()) {
			int temp_cnt = temp.top().first;
			int temp_num = temp.top().second;
			temp.pop();
			if (temp_r - 1 <= 100)
				A[temp_r-1][i] = temp_num;
			else
				break;
			if (temp_r <= 100)
				A[temp_r][i] = temp_cnt;
			else
				break;
			temp_r += 2;
		}
		if (r_cnt < temp_r-2)
			r_cnt = temp_r-2;
	}
}
int main() {
	int ans = 0;
	scanf("%d %d %d", &r, &c, &k);
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	r_cnt = 3;
	c_cnt = 3;
	while (!(A[r][c] == k)) {
		for (int i = 1; i <= r_cnt; i++) {
			for (int j = 1; j <= c_cnt; j++) {
				printf("%d ", A[i][j]);
			}
			printf("\n");
		}
		printf("%d %d\n", r_cnt, c_cnt);
		printf("\n");
		if (ans > 100)
			break;
		if (r_cnt >= c_cnt) {
			ans++;
			r_sort();
		}
		else {
			c_sort();
			ans++;
		}
	}

	if (ans > 100)
		printf("-1");
	else
		printf("%d", ans);
	return 0;
}