//2015004439_±èÀçÈ«_508
#include <stdio.h>
#include <queue>
using namespace std;
int n, from, to, w, num;
int k1, k2, r[1005];
priority_queue<pair<int, pair<int, int> > > q;
int findkey(int s)
{
	if (r[s] <= 0)
		return s;
	else
		return r[s] = findkey(r[s]);
}

void Union(int k1, int k2)
{
	if (r[k1] > r[k2]) 
		r[k1] = k2;
	else
	{
		if (r[k1] == r[k2])
			r[k1]--;
		r[k2] = k1;
	}
}

int main()
{
	int i;
	scanf("%d", &n);
	while (scanf("%d %d %d", &from, &to, &w) != EOF)
	{
		if (from < to)
			q.push({ -w,{-from,-to} });
		else
			q.push({ -w,{-to,-from} });
	}
	printf("%d\n", n - 1);
	while (!q.empty())
	{
		from = -q.top().second.first;
		to = -q.top().second.second;
		w = -q.top().first;
		q.pop();
		k1 = findkey(from);
		k2 = findkey(to);
		if (k1 != k2)
		{
			num++;
			Union(k1, k2);
			printf("%d %d %d\n", from, to, w);
			if (num == n - 1)
				break;
		}
	}
	return 0;
}