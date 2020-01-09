#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int n, m;
char map[11][11];//0 À§ 1 ¾Æ·¡ 2 ¿Þ 3 ¿À
int answer = 987654321;
int reverse(int dir) {
	if (dir == 0) 
		return 1;
	else if (dir == 1)
		return 0;
	else if (dir == 2)
		return 3;
	else
		return 2;
}
void solution(int rx, int ry, int bx, int by, int cnt, int dir) {
	int r_flag = 0;
	int b_flag = 0;
	int nrx = rx;
	int nry = ry;
	int nbx = bx;
	int nby = by;
	if (cnt > 10 || cnt >= answer)
		return;
	while (1) {//red ball move
		if (dir == 0) {
			if (map[rx - 1][ry] == '#') {
				break;
			}
			else {
				rx -= 1;
			}
			if (map[rx][ry] == 'O') {
				r_flag = 1;
				break;
			}
		}
		else if (dir == 1) {
			if (map[rx + 1][ry] == '#') {
				break;
			}
			else {
				rx += 1;
			}
			if (map[rx][ry] == 'O') {
				r_flag = 1;
				break;
			}
		}
		else if (dir == 2) {
			if (map[rx][ry-1] == '#') {
				break;
			}
			else {
				ry -= 1;
			}
			if (map[rx][ry] == 'O') {
				r_flag = 1;
				break;
			}
		}
		else if (dir == 3) {
			if (map[rx][ry+1] == '#') {
				break;
			}
			else {
				ry += 1;
			}
			if (map[rx][ry] == 'O') {
				r_flag = 1;
				break;
			}
		}
	}
	if (r_flag) {
		if (dir == 0)
			rx += 1;
		else if (dir == 1)
			rx -= 1;
		else if (dir == 2)
			ry += 1;
		else if (dir == 3)
			ry -= 1;
	}
	nrx = abs(nrx - rx);
	nry = abs(nry - ry);
	while (1) {//blue ball move
		if (dir == 0) {
			if (map[bx - 1][by] == '#') {
				break;
			}
			else {
				bx -= 1;
			}
			if (map[bx][by] == 'O') {
				b_flag = 1;
				break;
			}
		}
		else if (dir == 1) {
			if (map[bx + 1][by] == '#') {
				break;
			}
			else {
				bx += 1;
			}
			if (map[bx][by] == 'O') {
				b_flag = 1;
				break;
			}
		}
		else if (dir == 2) {
			if (map[bx][by - 1] == '#') {
				break;
			}
			else {
				by -= 1;
			}
			if (map[bx][by] == 'O') {
				b_flag = 1;
				break;
			}
		}
		else if (dir == 3) {
			if (map[bx][by + 1] == '#') {
				break;
			}
			else {
				by += 1;
			}
			if (map[bx][by] == 'O') {
				b_flag = 1;
				break;
			}
		}
	}
	if (b_flag) {
		if (dir == 0)
			bx += 1;
		else if (dir == 1)
			bx -= 1;
		else if (dir == 2)
			by += 1;
		else if (dir == 3)
			by -= 1;
	}
	nbx = abs(nbx - bx);
	nby = abs(nby - by);
	if (b_flag)
		return;
	else {
		if (r_flag) {
			if (answer > cnt)
				answer = cnt;
			return;
		}
	}
	if (rx == bx && ry == by) {
		if ((nrx + nry) > (nbx + nby)) {
			if (dir == 0) {
				rx += 1;
			}
			else if (dir == 1) {
				rx -= 1;
			}
			else if (dir == 2) {
				ry += 1;
			}
			else if (dir == 3) {
				ry -= 1;
			}
		}
		else {
			if (dir == 0) {
				bx += 1;
			}
			else if (dir == 1) {
				bx -= 1;
			}
			else if (dir == 2) {
				by += 1;
			}
			else if (dir == 3) {
				by -= 1;
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		if (i == dir)
			continue;
		if (i == reverse(dir))
			continue;
		solution(rx, ry, bx, by, cnt + 1, i);
	}
}
int main() {
	scanf("%d %d\n", &n, &m);
	int rx, ry;
	int bx, by;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				rx = i;
				ry = j;
				map[i][j] == '.';
			}
			else if (map[i][j] == 'B') {
				bx = i;
				by = j;
				map[i][j] == '.';
			}
		}
	}
	for(int i = 0; i<4;i++)
		solution(rx, ry, bx, by, 1, i);
	if (answer > 10 || answer == 987654321)
		printf("-1");
	else
		printf("%d", answer);
	return 0;
}