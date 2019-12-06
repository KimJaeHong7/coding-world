//2015004439_±èÀçÈ«_508
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
void adjust(int a[], int root, int n) {
	int child = 2 * root;
	int temp = a[root];
	while (child <= n) {
		if (a[child] < a[child + 1] && child < n) {
			child++;
		}
		if (temp > a[child]) {
			break;
		}
		else {
			a[child / 2] = a[child];
			child = child * 2;
		}
	}
	a[child / 2] = temp;
}
void heapsort(int a[], int i, int count) {
	int tmp;
	int p, k;
	for (p = i / 2; p >= 1; p--) {
		adjust(a, p, i);
	}
	printf("\n");
	for (k = i - 1; k > (i - 1 - count); k--) {
		tmp = a[k + 1];
		a[k + 1] = a[1];
		a[1] = tmp;
		adjust(a, 1, k);
	}

}

int main() {
	int heap[100000];
	int num, k, a, n;
	scanf("%d %d", &num, &k);
	while (1) {
		if (num > 100000 || k > 30) {
			scanf("%d %d", &num, &k);
		}
		else
			break;
	}
	for (n = 1; n <= num; n++)
		scanf("%d", &heap[n]);
	heapsort(heap, num, k);
	for (a = num; a > num - k; a--) {
		printf("%d ", heap[a]);
	}
	printf("\n");
	for (a = 1; a <= num - k; a++) {
		printf("%d ", heap[a]);
	}
	printf("\n");
	return 0;
}