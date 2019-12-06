//2015004439_±èÀçÈ«_508
#include <stdio.h>

int r[1005], connect[1005];
int findkey(int s)
{
	if (r[s] <= 0)
		return s;
	else
		return r[s] = findkey(r[s]);
}

void Union(int rep1, int rep2)
{
	if (r[rep1] > r[rep2])
		r[rep1] = rep2;
	else
	{
		if (r[rep1] == r[rep2])
			r[rep1]--;
		r[rep2] = rep1;
	}
}

int main()
{
	int i, n;
	int x, y, k, rep1, rep2, count;
	scanf("%d", &n);
	while (scanf("%d %d", &x, &y) != EOF)
	{
		rep1 = findkey(x);
		rep2 = findkey(y);
		if (rep1 != rep2)
			Union(rep1, rep2);
	}
	for (i = 1; i <= n; i++)
	{
		k = findkey(i);
		if (connect[k] == 0) {
			count++;
			connect[i] = connect[k] = count;
		}
		else connect[i] = connect[k];
	}
	printf("%d\n", count);
	for (i = 1; i <= n; i++)
		printf("%d\n", connect[i]);
	return 0;
}