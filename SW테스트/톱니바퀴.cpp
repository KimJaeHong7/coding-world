#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
int k;
int sum;
char top1[8];
char top2[8];
char top3[8];
char top4[8];
int state[4];
int c[4];
int visit[4];
void rotate(int num, int dir);
void init() {
	for (int i = 0; i < 4; i++) {
		state[i] = 0;
		visit[i] = 0;
		c[i] = 0;
	}
}
void clock_wise(char temp[8]) {
	char tmp = temp[0];
	temp[0] = temp[7];
	temp[7] = temp[6];
	temp[6] = temp[5];
	temp[5] = temp[4];
	temp[4] = temp[3];
	temp[3] = temp[2];
	temp[2] = temp[1];
	temp[1] = tmp;
}
void counter_wise(char temp[8]) {
	char tmp = temp[0];
	temp[0] = temp[1];
	temp[1] = temp[2];
	temp[2] = temp[3];
	temp[3] = temp[4];
	temp[4] = temp[5];
	temp[5] = temp[6];
	temp[6] = temp[7];
	temp[7] = tmp;
}
void check(int num, int dir) {
	if (num == 1) {
		if (visit[1] != 1 && top1[2] != top2[6]) {
			state[1] = 1;
			visit[1] = 1;
			c[1] = dir;
			check(2, -dir);
		}
	}
	else if (num == 2) {
		if (visit[2] != 1 && top2[2] != top3[6]) {
			state[2] = 1;
			visit[2] = 1;
			c[2] = dir;
			check(3, -dir);
		}
		if (visit[0] !=1 && top2[6] != top1[2]) {
			state[0] = 1;
			visit[0] = 1;
			c[0] = dir;
			check(1, -dir);
		}
	}
	else if (num == 3) {
		if (visit[1] != 1 && top3[6] != top2[2]) {
			state[1] = 1;
			visit[1] = 1;
			c[1] = dir;
			check(2,-dir);
		}
		if (visit[3] != 1 && top3[2] != top4[6]) {
			state[3] = 1;
			visit[3] = 1;
			c[3] = dir;
			check(4,-dir);
		}
	}
	else if (num == 4) {
		if (visit[2] != 1 && top4[6] != top3[2]) {
			state[2] = 1;
			visit[2] = 1;
			c[2] = dir;
			check(3,-dir);
		}
	}
}
void rotate(int num, int dir) {
	state[num - 1] = 1;
	visit[num - 1] = 1;
	c[num - 1] = dir;
	check(num, -dir);
	if (state[0] == 1) {
		if (c[0] == 1) {
			clock_wise(top1);
		}
		else
			counter_wise(top1);
	}
	if (state[1] == 1) {
		if (c[1] == 1) {
			clock_wise(top2);
		}
		else
			counter_wise(top2);
	}
	if (state[2] == 1) {
		if (c[2] == 1) {
			clock_wise(top3);
		}
		else
			counter_wise(top3);
	}
	if (state[3] == 1) {
		if (c[3] == 1) {
			clock_wise(top4);
		}
		else
			counter_wise(top4);
	}
}
int main() {
	for (int i = 0; i < 8; i++) {
		cin >> top1[i];
	}
	for (int i = 0; i < 8; i++) {
		cin >> top2[i];
	}
	for (int i = 0; i < 8; i++) {
		cin >> top3[i];
	}
	for (int i = 0; i < 8; i++) {
		cin >> top4[i];
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int num, dir;
		scanf("%d %d", &num, &dir);
		rotate(num, dir);
		init();
	}
	if (top1[0] == '1')
		sum += 1;
	if (top2[0] == '1')
		sum += 2;
	if (top3[0] == '1')
		sum += 4;
	if (top4[0] == '1')
		sum += 8;
	printf("%d", sum);
	return 0;
}