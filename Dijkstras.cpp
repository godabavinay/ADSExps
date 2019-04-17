// Dijkstras algorithm
#include <stdio.h>
#define INF 999

int G[10][10], n;

int minDistance(int dist[], int sptSet[]) {
	int min = INF, min_index = -1, i;
	for(i = 0; i < n; i++)
		if(!sptSet[i] && dist[i] < min)
			min = dist[i], min_index = i;
	return min_index;		
}

void dijkstras(int src, int dst) {
	int dist[n];
	int sptSet[n];
	int i, u, v;
	for(i = 0; i < n; i++) {
		dist[i] = INF;
		sptSet[i] = 0;
	}
	dist[src] = 0;
	for(i = 0; i < n-1; i++) {
		u = minDistance(dist, sptSet);
		sptSet[u] = 1;
		for(v = 0; v < n; v++)
			if(!sptSet[v] && G[u][v] && dist[u] != INF && dist[u] + G[u][v] < dist[v])
				dist[v] = dist[u] + G[u][v];
	}
	printf("The shortest distance between source and destination: %d", dist[dst]);
}

int main() {
	int i, j, src, dst;
	printf("Enter the no of vertices: ");
	scanf("%d", &n);
	printf("Enter the adjacency matrix of the graph:\n");
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			scanf("%d", &G[i][j]);
	printf("Enter the Source and destination: ");
	scanf("%d%d", &src, &dst);
	dijkstras(src, dst);	
}
