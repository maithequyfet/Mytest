#include <stdio.h>
#include <stdlib.h>

struct t_node{
	int element;
	struct t_node *next;
}T_NODE;

T_Node *gNode;

void CreateNode(int element){
	T_Node *tempNode;
	tempNode = (T_Node*)malloc(sizeof(T_Node));
	if(gNode = NULL){
		tempNode = gNode;
		gNode->next = NULL;
	}
    else{
		tempNode->next = gNode;
		
	}
	
}
void addLast;
void removeFirst;
void removeLast;
void display;
void count;


