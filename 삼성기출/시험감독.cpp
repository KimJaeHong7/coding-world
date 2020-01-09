#include <stdio.h>
#include <iostream>

using namespace std;

long long N, B, C;
long long A[1000001];
long long answer;
int main() {
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
	}
	scanf("%lld %lld", &B, &C);
	for (int i = 0; i < N; i++) {
		A[i] -= B;
		if (A[i] > 0) {
			if (A[i] % C == 0) {
				answer += A[i] / C;
			}
			else {
				answer += (A[i] / C) + 1;
			}
		}
	}
	answer += N;
	printf("%lld", answer);
	return 0;
}