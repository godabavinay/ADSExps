// DFS
#include <stdio.h>
int G[10][10], visited[10], n;

void DFS(int i) {
	int j;
	printf(" %d", i);
	visited[i] = 1;
	for(j = i; j < n; j++) {
		if(!visited[j] && G[i][j])
			DFS(j);
	}
	for(j = 0; j < i; j++) {
		if(!visited[j] && G[i][j])
			DFS(j);
	}
}

void ReadAdjacencyMatrix() {
	int i, j;
	printf("\nEnter the adjacency matrix:\n");
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			scanf("%d", &G[i][j]);
		}
	}
}

int main() {
	printf("Enter the no of vertices: ");
	scanf("%d", &n);
	ReadAdjacencyMatrix();
	printf("DFS:");
	DFS(0);
}
