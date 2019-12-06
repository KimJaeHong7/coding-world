//2015004439_±èÀçÈ«_508
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
void selectSort(int a[], int line, int count) {
	int tmp;
	for (int i = 0; i <= count-1; i++) {
		int min = i;
		for (int j = i+1; j < line; j++) {
			if (a[min] > a[j]) {
				min = j;
			}
		}
		tmp = a[min];
		a[min] = a[i];
		a[i] = tmp;
	}
}
int main() {
	int count, line;
	int a[30000];
	int i;
	scanf("%d %d", &line, &count);
	while (1) {
		if (line > 30000 || count > 30000) {
			scanf("%d %d", &line, &count);
		}
		else
			break;
	}
	for (i = 0; i < line; i++) {
		scanf("%d", &a[i]);
	}
	selectSort(a, line,count);
	printf("\n");

	for (int k = 0; k < line; k++) {
		printf("%d\n", a[k]);
	}
	return 0;
}