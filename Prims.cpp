// Prim's Algorithm
#include <stdio.h>
#define INF 999
int G[10][10], selected[10], n;

void prims() {
	int noOfEdges = 0, x, y, i, j;
	selected[0] = 1;
	printf("\nEDGE WEIGHT\n");
	while(noOfEdges < n-1) {
		int min = INF;
		x = 0;
		y = 0;
		for(i = 0; i < n; i++) {
			if(selected[i]) {
				for(j = 0; j < n; j++) {
					if(!selected[j] && G[i][j]) {
						if(G[i][j] < min) {
							min = G[i][j];
							x = i;
							y = j;
						}
					}
				}
			}
		}
		printf("%d-%d : %d\n", x, y, G[i][j]);
		selected[y] = 1;
		noOfEdges++;
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
	prims();	
}
