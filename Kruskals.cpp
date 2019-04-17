// Kruskals Algorithm
#include <stdio.h>
#define INF 999

int G[10][10], n, parent[10];

int find(int i) {
	while(parent[i] != i)
		i = parent[i];
	return i;	
}

void union1(int i, int j) {
	int a = find(i);
	int b = find(j);
	parent[a] = b;
}

void kruskals() {
	int i, j, noOfEdges = 0;
	
	for(i = 0; i < n; i++)
		parent[i] = i;
	
	while(noOfEdges < n-1) {
		int min = INF, a = -1, b = -1;
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				if(find(i) != find(j) && G[i][j] < min && G[i][j] != 0) {
					min = G[i][j];
					a = i;
					b = j;
				}
			}
		}
		union1(a, b);
		printf("%d-%d : %d\n", a, b, min);
		noOfEdges++;
	}	
}

int main() {
	int i, j;
	printf("Enter the no of vertices: ");
	scanf("%d", &n);
	printf("Enter the adjacency matrix of the graph:\n");
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			scanf("%d", &G[i][j]);
	kruskals();
}
