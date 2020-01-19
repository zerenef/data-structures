#include <stdio.h>
#include <stdlib.h>

struct qnode{ int key;  struct qnode *next; };
struct queue{ struct qnode *front, *rear; };

struct qnode *newNode(int key){
  struct qnode *inTheQueue = (struct qnode *)malloc(sizeof(struct qnode));
  inTheQueue->key = key;
  inTheQueue->next = NULL;
  return inTheQueue;
}

struct queue *createQueue(){
  struct queue *q = (struct queue*)malloc(sizeof(struct queue));
  q->front = q->rear = NULL;
  return q;
}

void enqueue(struct queue *q, int key){
  struct qnode *inTheQueue = newNode(key);
  printf("%d kuyruga girdi\n", key);

  if (q->rear == NULL){
    q->front = q->rear = inTheQueue;
    return;
  }

  q->rear->next = inTheQueue;
  q->rear = inTheQueue;
}

int dequeue(struct queue *q){
  if (q->front == NULL){
    printf("kuyruk bos\n");
    return -1;
  } 

  struct qnode *queued = q->front;
  q->front = q->front->next;

  int popped = queued->key;
  free(queued);

  if (q->front == NULL)
    q->rear = NULL;
  printf("kuyruktan %d cikti\n", popped);
  return popped;
}

int front(struct queue *q){
  if (q->front == NULL) return -1;
  return q->front->key;
}

int rear(struct queue *q){
  if (q->rear == NULL) return -1;
  return q->rear->key;
}

int main(){
  struct queue *q = createQueue();
  enqueue(q, 10);
  dequeue(q);
  enqueue(q, 20);
  enqueue(q, 30);
  dequeue(q);
  printf("ondeki %d\narkadaki %d\n", front(q), rear(q));
  
  return 0;
}