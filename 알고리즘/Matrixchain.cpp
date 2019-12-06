//2015004439_±èÀçÈ«_508
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
int num = 1;
void printParense(int s[][100], int i, int j) {
	int a = i;
	int b = j;
	if (i == j) {
		printf("%d ", num);
		num++;
	}
	else {
		printf("( ");
		printParense(s, i, s[a][b]);
		printParense(s, s[a][b] + 1, j);
		printf(") ");
	}
}
int main() {
	int N, j;
	int s = 0;
	int p[101];
	int S[100][100] = { 0 };
	int M[100][100];
	while (1) {
		scanf("%d", &N);
		if (N < 1 || N>100)
			scanf("%d", &N);
		else
			break;
	}
	for (int c = 0; c <= N; c++)
		scanf("%d", &p[c]);
	for (int i = 1; i <= N; i++) {
		M[i][i] = 0;
	}
	for (int l = 2; l <= N; l++) {
		for (int i = 1; i <= N - l + 1; i++) {
			j = i + l - 1;
			M[i][j] = 1000000;
			for (int k = i; k < j; k++) {
				if (M[i][j] > M[i][k] + M[k + 1][j] + p[i - 1] * p[k] * p[j]) {
					M[i][j] = M[i][k] + M[k + 1][j] + p[i - 1] * p[k] * p[j];
					s = k;
				}
			}
			S[i][j] = s;
		}
	}
	printf("%d\n", M[1][N]);
	printParense(S, 1, N);
	return 0;
}