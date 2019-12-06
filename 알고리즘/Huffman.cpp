//2015004439_±èÀçÈ«_508
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

struct element {
	int num;
	int index;
	char c[4];
	int lchild;
	int rchild;
};
element h[30001];
element h1[60001];
int static Sum = 0;
int bit = 0;
void heapify(struct element *h, int root, int size) {
	int child = root * 2;
	element temp = h[root];
	while (child <= size) {
		if (h[child].num > h[child + 1].num && child < size)
			child++;
		if (temp.num < h[child].num)
			break;
		else {
			h[child / 2] = h[child];
			child = child * 2;
		}
	}
	h[child / 2] = temp;
}
void min_heap(struct element *h, int n) {
	for (int i = n / 2; i >= 1; i--)
		heapify(h, i, n);
}
void fixed_length(int n, int s) {
	int count = 0;
	while (n >= 1) {
		n = n / 2;
		count++;
	}
	printf("%d\n", count*s);
}
element makeNode(struct element e1, struct element e2, int n) {
	element node;
	node.num = e1.num + e2.num;
	node.index = n + 1;
	node.lchild = e1.index;
	node.rchild = e2.index;
	return node;
}
void insert(struct element *h, struct element e1, struct element e2, int size, int n) {
	size += 1;
	h[size].num = e1.num + e2.num;
	h[size].index = n + 1;
	h[size].lchild = e1.index;
	h[size].rchild = e2.index;
	heapify(h, size, size);
}
element delete_h(struct element *h, int size) {
	element temp = h[1];
	h[1] = h[size];
	heapify(h, 1, size - 1);
	return temp;
}
void huffman(element e, int k, int bit) {
	e = h1[k];
	if (e.rchild == 0 && e.lchild == 0) {
		Sum = Sum + bit * e.num;
	}
	else if (e.rchild == 0 && e.lchild != 0) {
		huffman(e, e.lchild, bit + 1);
	}
	else if (e.lchild == 0 && e.rchild != 0) {
		huffman(e, e.rchild, bit + 1);
	}
	else {
		huffman(e, e.rchild, bit + 1);
		huffman(e, e.lchild, bit + 1);
	}
}
int main() {
	int n, a, s, k, b, c;
	int j = 1;
	int bit = 0;
	element e1, e2, e, node;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s %d", &h[i].c, &h[i].num);
		h[i].lchild = h[i].rchild = 0;
		h[i].index = i;
		h1[i] = h[i];

	}
	scanf("%d", &s);
	fixed_length(n, s);
	a = b = c = n;
	min_heap(h, n);
	k = 1;
	while (n - 1 > 0) {
		e1 = delete_h(h, n);
		n = n - 1;
		e2 = delete_h(h, n);
		n = n - 1;
		node = makeNode(e1, e2, c);
		c = c + 1;
		h1[a + j] = node;
		h1[a + j].index = a + j;
		j++;
		insert(h, e1, e2, n, b);
		b = b + 1;
		n = n + 1;
		k = a + j - 1;
	}
	e = h[1];
	huffman(e, k, bit);

	printf("%d\n", Sum);
	return 0;
}