#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#define MIN_ELEMENTS 100000
#define HEAP_FULL(n) (n==MIN_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)

typedef struct {
	int key;
}element;

element heap[MIN_ELEMENTS];
int n = 0;

void insert_min_heap(element item, int *n) {
	int i;
	i = ++(*n);
	while ((i != 1) && (abs(item.key) <= abs(heap[i / 2].key))) {
		if ((abs(item.key) == abs(heap[i / 2].key))) {
			if (item.key < heap[i / 2].key) {
				heap[i] = heap[i / 2];
				i /= 2;
			}
			else if (item.key == heap[i / 2].key) {
				heap[(i / 2) + 1] = item;
				break;
			}
		}
		else {
			heap[i] = heap[i / 2];
			i /= 2;
		}
	}
	if (item.key != heap[i / 2].key)
		heap[i] = item;
}

element delete_min_heap(int *n) {
	element item, temp;
	if (HEAP_EMPTY(*n)) {
		item.key = 0;
		return item;
	}
	item = heap[1];
	temp = heap[(*n)--];
	int parent = 1;
	int child = 2;

	while (child <= *n) {
		if ((child < *n) && (abs(heap[child].key) > abs(heap[child + 1].key)))
			child++;
		else if ((child < *n) && (abs(heap[child].key) == abs(heap[child + 1].key))) {
			if (heap[child].key > heap[child + 1].key)
				child++;
		}
		if (abs(temp.key) <= abs(heap[child].key))
			break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;

	return item;
}
int main() {
	int q;
	element u;
	int num;
	int p = 1;
	scanf("%d", &q);

	while (p <= q) {
		scanf("%d", &num);
		u.key = num;
		switch (num) {
		case 0:
			printf("%d\n", delete_min_heap(&n).key);
			break;
		default:
			insert_min_heap(u, &n);
			break;
		}
		p++;
	}
	return 0;
}