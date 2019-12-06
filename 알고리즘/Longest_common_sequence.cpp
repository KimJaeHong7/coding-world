//2015004439_±èÀçÈ«_508
#include <stdio.h>
#include <stdlib.h>

int MAX(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}
int _strlen(char* str) {
	int size = 0;
	while (str[size++]);
	return size - 1;
}
void strAdd(char *str) {
	if (_strlen(str) == 0) {
		str[0] = '\0';
		return;
	}
	int cur = 0;
	char tmp = str[cur];
	char tmp2;
	while (str[cur]) {
		tmp2 = str[cur + 1];
		str[cur + 1] = tmp;
		tmp = tmp2;
		cur++;
	}
	str[cur + 1] = '\0';
	str[0] = '0';
}

int main() {
	int _table[501][501] = { 0, };
	char str1[500];
	char str2[500];
	int len1, len2, i, j;

	scanf("%s", str1);
	scanf("%s", str2);
	strAdd(str1);
	strAdd(str2);

	len1 = _strlen(str1);
	len2 = _strlen(str2);

	for (i = 1; i < len1; i++) {
		for (j = 1; j < len2; j++) {
			if (str1[i] == str2[j]) {
				_table[i][j] = _table[i - 1][j - 1] + 1;
			}
			else {
				_table[i][j] = MAX(_table[i - 1][j], _table[i][j - 1]);
			}
		}
	}
	char lcs[500] = { '\0' };
	int len3 = _table[len1 - 1][len2 - 1] - 1;

	i = len1 - 1;
	for (j = len2 - 1; j > 0;) {
		if (_table[i][j] == _table[i][j - 1]) {
			j--;
		}
		else if (_table[i][j] == _table[i - 1][j]) {
			i--;
		}
		else if (_table[i - 1][j] == _table[i][j - 1]) {
			lcs[len3] = str2[j--];
			i--;
		}

	}
	printf("%s\n", lcs);
	return 0;
}