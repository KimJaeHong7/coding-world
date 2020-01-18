#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

int N;
int min_ = 100000000;
int S[20][20];
int check[20];
vector<int> start;
void cal() {
	vector<int> link;
	for (int i = 0; i < N; i++) {
		if (check[i] == 0)
			link.push_back(i);
	}
	int start_sum = 0;
	int link_sum = 0;
	for (int i = 0; i < N/2; i++) {
		for (int j = 0; j < N/2; j++) {
			if (i == j)
				continue;
			else {
				start_sum += S[start[i]][start[j]];
			}
		}
	}
	for (int i = 0; i < N/2; i++) {
		for (int j = 0; j < N/2; j++) {
			if (i == j)
				continue;
			else {
				link_sum += S[link[i]][link[j]];
			}
		}
	}
	if (min_ > abs(link_sum - start_sum))
		min_ = abs(link_sum - start_sum);
	link.clear();
}
void maketeam(int cnt) {
	if (cnt == (N / 2)-1) {
		cal();
	}
	for (int i = 1; i < N; i++) {
		if (start.back() > i)
			continue;
		if (check[i] == 0) {
			check[i] = 1;
			start.push_back(i);
			maketeam(cnt + 1);
			start.pop_back();
			check[i] = 0;
		}
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &S[i][j]);
		}
	}
	check[0] = 1;
	start.push_back(0);
	maketeam(0);
	printf("%d", min_);
	return 0;
}