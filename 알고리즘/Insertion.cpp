//2015004439_±èÀçÈ«_508
#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define N 30000
void insert(int a[], int end) {
	int key, i, j;
	for (i = 1; i < end; i++) {
	key = a[i];
	for (j = i; j > 0 && a[j - 1] < key; j--)
		a[j] = a[j - 1];
	a[j] = key;
	}
}
int main()
{
	int i, nx;
	int x[N];
	scanf("%d", &nx);
	while (1) {
		if (nx > 30000) {
			scanf("%d", &nx);
		}
		else
			break;
	}
	for (i = 0; i < nx; i++)
		scanf("%d", &x[i]);
	insert(x, nx);
	for (i = 0; i < nx; i++)
		printf("%d\n", x[i]);

	return 0;
}