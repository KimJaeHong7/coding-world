#include <iostream>
#include <stdio.h>

using namespace std;
int N, min_ = 1000000001, max_ = -1000000001;
int num[11];
int op[4];
void solve(int cnt, int sum) {
	if (cnt == N - 1) {
		if (sum < min_)
			min_ = sum;
		if (sum > max_)
			max_ = sum;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (op[i] == 0)
			continue;
		else {
			if (i == 0) {
				op[i]--;
				solve(cnt + 1, sum + num[cnt + 1]);
				op[i]++;
			}
			else if (i == 1) {
				op[i]--;
				solve(cnt + 1, sum - num[cnt + 1]);
				op[i]++;
			}
			else if (i == 2) {
				op[i]--;
				solve(cnt + 1, sum * num[cnt + 1]);
				op[i]++;
			}
			else if (i == 3) {
				op[i]--;
				solve(cnt + 1, sum / num[cnt + 1]);
				op[i]++;
			}
		}
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &num[i]);
	for (int i = 0; i < 4; i++)
		scanf("%d", &op[i]);
	solve(0, num[0]);
	printf("%d\n", max_);
	printf("%d\n", min_);
	return 0;
}