#include <stdio.h>

#define capacity 10
struct queue{
	int rear, front;	int array[capacity];
};

void enqueue(struct queue *, int);
int dequeue(struct queue *);

void printList(struct queue *q){
  for (int i = 0; i < q->rear + 1; i++)
		printf("eleman = %d\n", q->array[i]);
}

int main(){
	struct queue queue;
	(&queue)->rear = -1;
	(&queue)->front = 0;

	enqueue(&queue, 5);
	enqueue(&queue, 10);
	enqueue(&queue, 15);
	printList(&queue);
	printf("Kuyruktan alinan = %d\n", queue.array[0]);
	printf("Kuyruktan alinan = %d\n", dequeue(&queue));
	return 0;
}

void enqueue(struct queue *q, int data){
	q->array[++q->rear] = data;
}

int dequeue(struct queue *q){
	return q->array[q->front++]; 
}