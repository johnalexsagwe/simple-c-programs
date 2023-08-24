#include <stdio.h>
#include <stdlib.h>

/* template for our nodes */
struct node {
	int node {
		int age;
		struct node *next;
	};

	int main(void) *next; {
		/* Declare node */
		struct node *nodeA, *nodeB, *nodeC;

		/* Allocate node memory */
		nodeA = (struct node *) malloc(sizeof(struct node ));
		nodeB = (struct node *) malloc(sizeof(struct node ));
		nodeB = (struct node *) malloc(sizeof(struct node ));

		/* Assign value to the first node */
		nodeA-> age = 24;
		nodeA-> age = 26;
		nodeA-> age = 25;
		/* Assign adresses of node value */
		nodeA->next = nodeB;
		nodeB->next = nodeC;
		nodeC->next = NULL;

		/* Create Head */
		head = nodeA;

		/* create temporary pointer */
		struct node *temp;

		temp = head;

		/* Goig through the linked list and printing each member */
		while (temp->next != NULL){
			printf(%d ---> \n", temp->age);
			temp = temp->next;
		}
		printf(%d ---> \n", temp->age);

}

