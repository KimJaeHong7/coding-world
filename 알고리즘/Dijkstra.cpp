//2015004439_±èÀçÈ«_508
#include<stdio.h>
#include<queue>
#include<vector>
#include<iostream>

using namespace std;

#define INF 987654321

typedef pair<int, int> pii;
vector<pii> list[5001];
pii g;
priority_queue<pii, vector<pii>, greater<pii> > Q;

int dist[5001];
int V, E;

void dijkstra(int k) {
	dist[k] = 0;
	g.first = 0;
	g.second = k;
	Q.push(g);
	while (!Q.empty()) {
		pii u = Q.top();
		Q.pop();
		int weight = u.first;
		int vertex = u.second;
		if (dist[vertex] < weight) 
			continue;
		for (int i = 0; i < list[vertex].size(); i++) {
			int nextV = list[vertex][i].first;
			int nextW = list[vertex][i].second;
			if (dist[nextV] > dist[vertex] + nextW) {
				dist[nextV] = dist[vertex] + nextW;
				g.first = dist[nextV];
				g.second = nextV;
				Q.push(g);
			}
		}
	}
}
int main() {

	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)   
		dist[i] = INF;

	for (int i = 1; i <= n; i++) {
		int u, v, w, temp;
		scanf("%d %d", &u, &temp);
		for (int j = 1; j <= temp; j++) {
			scanf("%d %d", &v, &w);
			g.first = v;
			g.second = w;
			list[u].push_back(g);
		}
	}

	dijkstra(1);

	int temp = 0;

	for (int i = 1; i <= n; i++) {
		if (temp < dist[i])  temp = dist[i];
	}

	printf("%d\n", temp);

	return 0;
}