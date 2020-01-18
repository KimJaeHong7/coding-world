#include <stdio.h>
#include <iostream>

using namespace std;
int n, max_;
int T[16];
int P[16];
int check[16];
void solution(int start, int sum) {
	if (max_ < sum)
		max_ = sum;
	for (int i = 0; i < T[start]; i++) {
		if(start+i <= n)
			check[start + i] = 1;
	}
	for (int i = start + 1; i <= n; i++) {
		if (check[i] != 1) {
			if (i + T[i]-1 <= n) {
				solution(i, sum + P[i]);
			}
		}
	}
	for (int i = 0; i < T[start]; i++) {
		if (start + i <= n)
			check[start + i] = 0;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &T[i], &P[i]);
	for (int i = 1; i <= n; i++) {
		if (i + T[i]-1 <= n) {
			solution(i, P[i]);
		}
	}
	printf("%d", max_);
	return 0;
}