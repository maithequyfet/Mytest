/*
 * linklist.c
 *
 *  Created on: 2017/08/30
 *      Author: 4000221
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
	int data;
	struct _Node *next;
}Node;

/* Add a node at the front */
void Push(Node **head, int newData){
	/* Allocate a new node */
	Node *newNode = (Node*)malloc(sizeof(Node));
	/* Push data into the new node */
	newNode->data = newData;
	/* Make new node points to head */
	newNode->next = (*head);
	/* Move head points to new node */
	(*head) = newNode;
}

/* Add a node after a given node */
void InsertAfter(Node *preNode, int newData){
	/* Check if the given prev_node is NULL */
    if (preNode == NULL)
    {
       printf("the given previous node cannot be NULL");
       return;
    }
	/* Allocate a new node */
	Node *newNode = (Node*)malloc(sizeof(Node));
	/* Push data into the new node */
	newNode->data = newData;
	/* Make next of new node as next of previous nod */
	newNode->next = preNode->next;
	/* Move next of previous node poits to new node */
	preNode->next = newNode;
}

/* Add a node at the end of list */
void Append(Node **headRef, int newData){
	/* Allocate a new node and last node */
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* lastNode = (Node*)malloc(sizeof(Node));
	/* Assign last node to head reference */
	lastNode = (*headRef);
	/* Push data into the new node */
	newNode->data = newData;
	newNode->next = NULL;
	/* If head note is empty, Then make new node as head */
	if(lastNode == NULL){
		*headRef = newNode;
		return;
	}
	/* Traverse to last node */
	while(lastNode->next != NULL){
		lastNode = lastNode->next;
	}
	lastNode->next = newNode;
}

/* Delete a node with key data */
void DeleteNode(Node **headRef, int keyData){
	Node *tempNode;
	Node *preNode;
	tempNode = *headRef;
	if(tempNode == NULL){
		printf("---------------");
		return;
	}
	/* Delete head node */
	if(tempNode->data == keyData){
		*headRef = tempNode->next;
		free(tempNode);
		return;
	}
	/* Delete another node */
	while(tempNode->data != keyData){
		preNode = tempNode;
		tempNode = tempNode->next;
	}
	preNode->next = tempNode->next;
	free(tempNode);
}

/* Delete a node with position of node */
void DeletePositionNode(Node **headRef, int pos){
	Node *tempNode;
	Node *preNode;
	int i = 1;
	tempNode = *headRef;
	if(NULL == tempNode){
		printf("---------------");
		return;
	}
	/* Delete first node */
	if(1 == pos){
		*headRef = tempNode->next;
		free(tempNode);
		return;
	}
	while(i != pos){
		i++;
		preNode = tempNode;
		tempNode = tempNode->next;
	}
	preNode->next = tempNode->next;
	free(tempNode);
}

void PrintList(Node *n){
	while(n != NULL){
		printf("%d ",n->data);
		n = n->next;
	}
}

/* Test common api of link list */
int main(){
	Node *head = NULL;
	Node *second = NULL;
	Node *third = NULL;

	head = (Node*)malloc(sizeof(Node));
	second = (Node*)malloc(sizeof(Node));
	third = (Node*)malloc(sizeof(Node));

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	Push(&head, 4);
	InsertAfter(second,5);
	Append(&head,6);
	PrintList(head);
	printf("\n");
	//DeleteNode(&head,4);
	DeletePositionNode(&head,1);
	PrintList(head);

	return 0;
}
