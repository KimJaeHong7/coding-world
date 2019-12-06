//2015004439_±èÀçÈ«_508
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
void adjust(int a[], int root, int size) {
	int child = 2 * root;
	int tmp = a[root];
	while (child <= size) {
		if (child < size &&a[child] <= a[child + 1]) {
			child++;
		}
		if (a[child] > tmp) {
			a[child / 2] = a[child];
			child = child * 2;
		}
		else
			break;
	}
	a[child / 2] = tmp;
}
void insert_key(int arr[], int key, int len) {
	int size = len + 1;
	int i;
	for (i = size; i / 2 >= 1; i /= 2) {
		if (arr[i / 2] < key) {
			arr[i] = arr[i / 2];
		}
		else break;
	}
	arr[i] = key;
}
int main() {
	int queue[100000];
	int max[100000];
	int index, num, key;
	int exit = 1;
	int size = 0;
	int count = 0;
	while (exit == 1) {

		scanf("%d", &index);
		switch (index) {
		case 0:
			exit = 0;
			break;
		case 1:
			scanf("%d", &key);
			if (size == 0)
				queue[1] = key;
			else
				insert_key(queue, key, size);
			size++;
			break;
		case 2:
			max[++count] = queue[1];
			queue[1] = queue[size];
			adjust(queue, 1, size - 1);
			size--;
			break;
		case 3:
			scanf("%d %d", &key, &num);
			queue[key] = num;
			if (key != 1 && queue[key] > queue[key / 2])
				insert_key(queue, num, key - 1);
			else
				adjust(queue, key, size);
			break;
		default:
			break;
		}


	}
	for (int i = 1; i <= count; i++)
		printf("%d ", max[i]);
	printf("\n");
	for (int j = 1; j <= size; j++)
		printf("%d ", queue[j]);
	return 0;
}