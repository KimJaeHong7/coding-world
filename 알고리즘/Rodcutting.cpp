//2015004439_±èÀçÈ«_508
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
int main() {
	int n, i, j;
	int p[105] = { 0 };
	int r[105] = { 0 };
	int s[105] = { 0 };
	scanf("%d", &n);
	while (1) {
		if (n > 100 || n < 1)
			scanf("%d", &n);
		else
			break;
	}
	for (i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	for (j = 1; j <= n; j++) {
		int q = 0;
		for (i = 1; i <= j; i++) {
			if (q < p[i] + r[j - i]) {
				q = p[i] + r[j - i];
				s[j] = i;
			}
		}
		r[j] = q;
	}
	printf("%d\n", r[n]);
	while (n > 0) {
		printf("%d ", s[n]);
		n = n - s[n];
	}
	printf("\n");
	return 0;
}