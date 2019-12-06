//2015004439_±èÀçÈ«_508
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
int main() {
	int a[3][101] = { 0 };
	int t[3][101] = { 0 };
	int l[3][101] = { 0 };
	int d[3][101] = { 0 };
	int way[101] = { 0 };
	int n, e1, e2, x1, x2, i,fast,last;
	while (1) {
		scanf("%d", &n);
		if (n < 1 || n>100)
			scanf("%d", &n);
		else
			break;
	}
	while (1) {
		scanf("%d %d", &e1, &e2);
		if (e1 < 1 || e1>100 || e2<1 || e2>100)
			scanf("%d %d", &e1, &e2);
		else
			break;
	}
	while (1) {
		scanf("%d %d", &x1, &x2);
		if (x1 < 1 || x1>100 || x2 < 1 || x2>100)
			scanf("%d %d", &x1, &x2);
		else
			break;
	}
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[1][i]);
		if (a[1][i] < 1 || a[1][i]>100)
			scanf("%d", &a[1][i]);
	}
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[2][i]);
		if (a[2][i] < 1 || a[2][i]>100)
			scanf("%d", &a[2][i]);
	}
	for (i = 1; i < n; i++) {
		scanf("%d", &t[1][i]);
		if (t[1][i] < 1 || t[1][i]>100)
			scanf("%d", &t[1][i]);
	}
	for (i = 1; i < n; i++) {
		scanf("%d", &t[2][i]);
		if (t[2][i] < 1 || t[2][i]>100)
			scanf("%d", &t[2][i]);
	}
	d[1][1] = e1 + a[1][1];
	d[2][1] = e2 + a[2][1];
	l[1][1] = 1;
	l[1][2] = 2;
	for (i = 2; i <= n; i++) {
		if (d[1][i - 1] + a[1][i] <= d[2][i - 1] + t[2][i - 1] + a[1][i]) {
			d[1][i] = d[1][i - 1] + a[1][i];
			l[1][i] = 1;
		}
		else {
			d[1][i] = d[2][i - 1] + t[2][i - 1] + a[1][i];
			l[1][i] = 2;
		}
		if (d[2][i - 1] + a[2][i] < d[1][i - 1] + t[1][i - 1] + a[2][i]) {
			d[2][i] = d[2][i - 1] + a[2][i];
			l[2][i] = 2;
		}
		else {
			d[2][i] = d[1][i - 1] + t[1][i - 1] + a[2][i];
			l[2][i] = 1;
		}
	}
	if (d[1][n] + x1 < d[2][n] + x2) {
		fast = d[1][n] + x1;
		last = 1;
	}
	else {
		fast = d[2][n] + x2;
		last = 2;
	}
	way[n] = last;
	for (i = n; i >1; i--) {
		way[i-1] = l[last][i];
		last = l[last][i];
	}
	printf("%d\n", fast);
	for (i = 1; i <= n; i++) {
		printf("%d %d", way[i], i);
		printf("\n");
	}
	return 0;
}