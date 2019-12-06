//2015004439_±èÀçÈ«_508
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int n, m,num;
	int max = 0;
	int count = 0;
	int a[100000] = { 0 };
	int b[100000] = { 0 };
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		a[num]++;
		if (num > max)
			max = num;
	}
	for (int j = 0; j < m; j++) {
		scanf("%d", &num);
		b[num]++;
		if (num > max)
			max = num;
	}
	for (int k = 1; k <= max; k++) {
		if (a[k] == 1 &&b[k]==1)
			count++;
	}
	printf("%d\n", count);
	return 0;
}