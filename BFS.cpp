// BFS
#include <stdio.h>
int G[10][10], visited[10], queue[10], n;
int front = -1, rear = -1;

void enQueue(int element) {
	if(front == -1)
		front = rear = 0;
	else 
		rear++;
	queue[rear] = element;
	visited[element] = 1;		
}

void deQueue() {
	if(front != -1 && front != rear+1) {
		printf(" %d", queue[front]);
		front++;
	}
}

void BFS() {
	int i, j;
	enQueue(0);
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(!visited[j] && G[i][j]) {
				enQueue(j);
			}
		}
		deQueue();
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
	printf("Enter no of vertices: ");
	scanf("%d", &n);
	ReadAdjacencyMatrix();
	printf("BFS:");
	BFS();
}
