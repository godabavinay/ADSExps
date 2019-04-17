// Static Hashing
#include <stdio.h>
#include <stdlib.h>
int hashTable[10];

int hash(int element) {
	int remainder = element % 10;
	int i;
	if(hashTable[remainder] == -1) {
		return remainder;
	} else {
		for(i = remainder; i < 10; i++) {
			if(hashTable[i] == -1)
				return i;
		}
		for(i = 0; i < remainder; i++) {
			if(hashTable[i] == -1)
				return i;
		}
		return -1;
	}
}

void insert(int element) {
	int hashIndex = hash(element);
	if(hashIndex == -1) {
		printf("\nInsertion is not possible");
	} else {
		hashTable[hashIndex] = element;
	}
}

void displayHashTable() {
	int i;
	for(i = 0; i < 10; i++) {
		printf("hash(%d) : %d\n", i, hashTable[i]);
	}
}

int main() {
	int i, choice, value;
	for(i = 0; i < 10; i++)
		hashTable[i] = -1;
	while(1) {
		printf("1.Insert 2.Display 3.Exit: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1: 
				printf("Enter a value: ");
				scanf("%d", &value);
				insert(value);
				break;
			case 2:
				displayHashTable();
				break;
			case 3:
				exit(0);		
		}
	}
}
