//2015004439_±èÀçÈ«_¾Ë°í¸®Áò
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define N 100000
void mergesort(int a[], int left, int middle, int right) {
	int i, j, k, m;
	i = left;
	j = middle + 1;
	k = left;
	int temp[N];
	while (i <= middle && j <= right) {
		if (a[i] > a[j]) {
			temp[k] = a[i];
			i++;
		}
		else {
			temp[k] = a[j];
			j++;
		}
		k++;
	}

	if (i > middle) {
		for (m = j; m <= right; m++) {
			temp[k] = a[m];
			k++;
		}
	}
	else {
		for (m = i; m <= middle; m++) {
			temp[k] = a[m];
			k++;
		}
	}
	for (m = left; m <= right; m++) {
		a[m] = temp[m];
	}
}
void merge(int a[], int left, int right) {
	int middle;
	if (left < right) {
		middle = (left + right) / 2;
		merge(a, left, middle);
		merge(a, middle + 1, right);
		mergesort(a, left, middle, right);
	}
}
int main() {
	int a[N];
	int num;
	int i, j;
	scanf("%d", &num);
	while (1) {
		if (num > 100000) {
			scanf("%d", &num);
		}
		else
			break;
	}
	for (i = 0; i < num; i++) {
		scanf("%d", &a[i]);
	}

	merge(a, 0, num - 1);
	for (j = 0; j < num; j++)
		printf("%d\n", a[j]);

	return 0;
}