#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *prev;
	struct node *next;
};

void printLinkedList(struct node *);
void addToTheHead(struct node **, int);
void insertAfter(struct node *, int);
void deleteAHeadNode(struct node **);
void addToTheEnd(struct node *, int);
void convert(struct node *, struct node *);

int main(){
	struct node *node1, *node2, *node3;
	node1 = (struct node *)malloc(sizeof(struct node));
	node2 = (struct node *)malloc(sizeof(struct node));
	node3 = (struct node *)malloc(sizeof(struct node));
	node1->data = 4;
	node2->data = 1;
	node3->data = 5;
	node1->prev = NULL;
	node1->next = node2;
	node2->prev = node1;
	node2->next = node3;
	node3->prev = node2;
	node3->next = NULL;
	printLinkedList(node1);

	addToTheHead(&node1, 9);
	printLinkedList(node1);

	insertAfter(node2, 8);
	printLinkedList(node1);

	deleteAHeadNode(&node1);
	printLinkedList(node1);

	addToTheEnd(node1, 14);
	printLinkedList(node1);

	struct node *node4 = (struct node *)malloc(sizeof(struct node));
	node4->data = 18;
	node4->next = NULL;
	convert(node1, node4);
	printLinkedList(node4);

	return 0;
}

// cift yonlu bagli listeyi yazdir
void printLinkedList(struct node *q){
	int length = 0;
	while (q != NULL){
		length++;
		printf("%d\n", q->data);
		q = q->next;
	}
	printf("eleman sayisi = %d\n\n", length);
	length = 0;
}

// basa ekle
void addToTheHead(struct node **head, int x){
	struct node *new_head = (struct node *)malloc(sizeof(struct node));
	new_head->data = x;
	new_head->prev = NULL;
	new_head->next = (*head);
	(*head)->prev = new_head;
	(*head) = new_head;
}

// verilen dugumden sonra ekle
void insertAfter(struct node *prev_node, int x){
	if (prev_node == NULL)
		return;
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = x;
	if(prev_node->next==NULL){
		addToTheEnd(prev_node,x);
	} else {
		new_node->next = prev_node->next;
		new_node->prev = prev_node;
		prev_node->next->prev = new_node;
		prev_node->next = new_node;
	}
	
}

// bastan silme
void deleteAHeadNode(struct node **head){
	struct node *ptr = (*head);
	(*head) = ptr->next;
	ptr->next->prev = NULL;
	free(ptr);
}

// sona ekle
void addToTheEnd(struct node *ptr, int x){
	struct node *node = (struct node *)malloc(sizeof(struct node));
	node->data = x;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = node;
	node->prev = ptr;
	node->next = NULL;
}

// tek basina bir dugume cift yonlu bagli listeyi ekle
void convert(struct node *ptr, struct node *singleHead){
	while (ptr != NULL){
		addToTheEnd(singleHead, ptr->data);
		ptr = ptr->next;
	}
}
