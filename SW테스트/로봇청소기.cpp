#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
int N, M, r, c, k;
int cnt;
			/*�� �� �� ��*/
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int temp[51][51];
/*dir =  ���� �ٶ󺸴� ����.
	0��, 1,�� 2,�� 3,��
*/
int find_dir(int dir) {
	if (dir == 0)
		return 3;
	else if (dir == 1)
		return 0;
	else if (dir == 2)
		return 1;
	else
		return 2;
}
void clean(int a, int b, int dir) {
	int i, j;
	int tmp = 0;/*��Ƚ��. ��, 4ȸ���� �Ǵ�*/
	int c = find_dir(dir);/*c�� ���� �ٶ󺸴� ������ ����*/
	if (temp[a][b] == 0) {
		cnt++;
		temp[a][b] = 2;
	}
	while (1) {
		if (tmp == 4) {
			int nextx = a - dx[dir];
			int nexty = b - dy[dir];
			if (nextx<0 || nextx>N - 1 || nexty<0 || nexty>M - 1 || temp[nextx][nexty]==1)
				return;
			else {
				a = nextx;
				b = nexty;
				tmp = 0;
				c = find_dir(dir);
				continue;
			}
		}
		i = a + dx[c];
		j = b + dy[c];
		if (i >= 0 && i <= N - 1 && j >= 0 && j<=M-1) {
			if (temp[i][j] == 0) {
				clean(i, j, c);
				break;
			}
			else {
				c -= 1;
				if (c < 0)
					c = 3;
			}
		}
		tmp++;
	}
}
int main() {
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r, &c, &k);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &temp[i][j]);
		}
	}
	clean(r, c, k);
	printf("%d", cnt);
	return 0;
}