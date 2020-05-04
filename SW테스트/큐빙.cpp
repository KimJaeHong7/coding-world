#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

char map[6][9];
int n;
void solution(char plain, char dir) {
	if (plain == 'U') {
		if (dir == '+') {
			char a = map[0][0];
			map[0][0] = map[0][6];
			map[0][6] = map[0][8];
			map[0][8] = map[0][2];
			map[0][2] = a;
			a = map[0][1];
			map[0][1] = map[0][3];
			map[0][3] = map[0][7];
			map[0][7] = map[0][5];
			map[0][5] = a;
			char temp = map[2][0];
			char temp1 = map[2][1];
			char temp2 = map[2][2];
			map[2][0] = map[5][2];
			map[2][1] = map[5][1];
			map[2][2] = map[5][0];
			map[5][0] = map[3][0];
			map[5][1] = map[3][1];
			map[5][2] = map[3][2];
			map[3][0] = map[4][2];
			map[3][1] = map[4][1];
			map[3][2] = map[4][0];
			map[4][0] = temp;
			map[4][1] = temp1;
			map[4][2] = temp2;
		}
	}
	else if (plain == 'D') {
		if (dir == '+') {
			char a = map[1][0];
			map[1][0] = map[1][2];
			map[1][2] = map[1][8];
			map[1][8] = map[1][6];
			map[1][6] = a;
			a = map[1][1];
			map[1][1] = map[1][5];
			map[1][5] = map[1][7];
			map[1][7] = map[1][3];
			map[1][3] = a;
			char temp = map[2][6];
			char temp1 = map[2][7];
			char temp2 = map[2][8];
			map[2][6] = map[4][6];
			map[2][7] = map[4][7];
			map[2][8] = map[4][8];
			map[4][6] = map[3][8];
			map[4][7] = map[3][7];
			map[4][8] = map[3][6];
			map[3][6] = map[5][6];
			map[3][7] = map[5][7];
			map[3][8] = map[5][8];
			map[5][6] = temp2;
			map[5][7] = temp1;
			map[5][8] = temp;
		}
	}
	else if (plain == 'F') {
		if (dir == '+') {
			char a = map[2][0];
			map[2][0] = map[2][6];
			map[2][6] = map[2][8];
			map[2][8] = map[2][2];
			map[2][2] = a;
			a = map[2][1];
			map[2][1] = map[2][3];
			map[2][3] = map[2][7];
			map[2][7] = map[2][5];
			map[2][5] = a;
			char temp = map[0][6];
			char temp1 = map[0][7];
			char temp2 = map[0][8];
			map[0][6] = map[4][8];
			map[0][7] = map[4][5];
			map[0][8] = map[4][2];
			map[4][2] = map[1][6];
			map[4][5] = map[1][7];
			map[4][8] = map[1][8];
			map[1][6] = map[5][8];
			map[1][7] = map[5][5];
			map[1][8] = map[5][2];
			map[5][2] = temp;
			map[5][5] = temp1;
			map[5][8] = temp2;
		}
	}
	else if (plain == 'B') {
		if (dir == '+') {
			char a = map[3][0];
			map[3][0] = map[3][2];
			map[3][2] = map[3][8];
			map[3][8] = map[3][6];
			map[3][6] = a;
			a = map[3][1];
			map[3][1] = map[3][5];
			map[3][5] = map[3][7];
			map[3][7] = map[3][3];
			map[3][3] = a;
			char temp = map[0][0];
			char temp1 = map[0][1];
			char temp2 = map[0][2];
			map[0][0] = map[5][0];
			map[0][1] = map[5][3];
			map[0][2] = map[5][6];
			map[5][0] = map[1][2];
			map[5][3] = map[1][1];
			map[5][6] = map[1][0];
			map[1][0] = map[4][0];
			map[1][1] = map[4][3];
			map[1][2] = map[4][6];
			map[4][0] = temp2;
			map[4][3] = temp1;
			map[4][6] = temp;
		}
	}
	else if (plain == 'L') {
		if (dir == '+') {
			char a = map[4][0];
			map[4][0] = map[4][6];
			map[4][6] = map[4][8];
			map[4][8] = map[4][2];
			map[4][2] = a;
			a = map[4][1];
			map[4][1] = map[4][3];
			map[4][3] = map[4][7];
			map[4][7] = map[4][5];
			map[4][5] = a;
			char temp = map[0][0];
			char temp1 = map[0][3];
			char temp2 = map[0][6];
			map[0][0] = map[3][6];
			map[0][3] = map[3][3];
			map[0][6] = map[3][0];
			map[3][0] = map[1][0];
			map[3][3] = map[1][3];
			map[3][6] = map[1][6];
			map[1][0] = map[2][6];
			map[1][3] = map[2][3];
			map[1][6] = map[2][0];
			map[2][0] = temp;
			map[2][3] = temp1;
			map[2][6] = temp2;
		}
	}
	else if (plain == 'R') {
		if (dir == '+') {
			char a = map[5][0];
			map[5][0] = map[5][2];
			map[5][2] = map[5][8];
			map[5][8] = map[5][6];
			map[5][6] = a;
			a = map[5][1];
			map[5][1] = map[5][5];
			map[5][5] = map[5][7];
			map[5][7] = map[5][3];
			map[5][3] = a;
			char temp = map[0][2];
			char temp1 = map[0][5];
			char temp2 = map[0][8];
			map[0][2] = map[2][2];
			map[0][5] = map[2][5];
			map[0][8] = map[2][8];
			map[2][2] = map[1][8];
			map[2][5] = map[1][5];
			map[2][8] = map[1][2];
			map[1][2] = map[3][2];
			map[1][5] = map[3][5];
			map[1][8] = map[3][8];
			map[3][2] = temp2;
			map[3][5] = temp1;
			map[3][8] = temp;
		}
	}
}
void map_init() {
	for (int i = 0; i < 9; i++) {
		map[0][i] = 'w';
	}
	for (int i = 0; i < 9; i++) {
		map[1][i] = 'y';
	}
	for (int i = 0; i < 9; i++) {
		map[2][i] = 'r';
	}
	for (int i = 0; i < 9; i++) {
		map[3][i] = 'o';
	}
	for (int i = 0; i < 9; i++) {
		map[4][i] = 'g';
	}
	for (int i = 0; i < 9; i++) {
		map[5][i] = 'b';
	}
}
int main() {
	string s;
	scanf("%d", &n);
	map_init();
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			cin >> s;
			if (s[1] == '-') {
				solution(s[0], '+');
				solution(s[0], '+');
			}
			solution(s[0], '+');
		}
		printf("%c%c%c\n", map[0][0], map[0][1], map[0][2]);
		printf("%c%c%c\n", map[0][3], map[0][4], map[0][5]);
		printf("%c%c%c\n", map[0][6], map[0][7], map[0][8]);
		map_init();
	}
	return 0;
}