//2015004439_±èÀçÈ«_508
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	int n, m, k, i, key;
	int *a, *b, *c, *d;
	scanf("%d %d %d", &n, &m, &k);
	while (1) {
		if (1 > n || n > 100000 || 1 > m || m > 100000 || 1 > k || k > 100000) {
			scanf("%d %d %d", &n, &m, &k);
		}
		else
			break;
	}
	a = (int*)malloc(sizeof(int)*k);
	b = (int*)malloc(sizeof(int)*k);
	c = (int*)malloc(sizeof(int)*m);
	d = (int*)malloc(sizeof(int)*m);
	memset(d, 0, m * sizeof(int));
	memset(c, 0, m * sizeof(int));
	for (i = 1; i <= k; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	for (i = 1; i <= n; i++) {
		scanf("%d", &key);
		c[key]++;
	}
	for (i = 1; i <= m; i++) {
		d[i] = c[i] + d[i - 1];
	}
	for (i = 1; i <= k; i++) {
		printf("%d\n", d[b[i]] - d[a[i] - 1]);
	}
	return 0;
}