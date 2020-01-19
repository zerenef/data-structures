#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct queue{
  int front, rear, size;
  unsigned capacity;
  int *array;
};

struct queue *createQueue(unsigned capacity){
  struct queue *queue = (struct queue*)malloc(sizeof(struct queue));
  queue->capacity = capacity;
  queue->front = queue->size = 0;
  queue->rear = capacity - 1;
  queue->array = (int *)malloc(queue->capacity * sizeof(int));
  return queue;
}

int isFull(struct queue *queue){
  return (queue->size == queue->capacity);
}

int isEmpty(struct queue *queue){
  return (queue->size == 0);
}

void enqueue(struct queue *queue, int item){
  if (isFull(queue)) return;
  queue->rear = (queue->rear + 1) % queue->capacity;
  queue->array[queue->rear] = item;
  queue->size += 1;
  printf("%d kuyruga eklendi\n", item);
}

int dequeue(struct queue *queue){
  if (isEmpty(queue)) return INT_MIN;
  int item = queue->array[queue->front];
  queue->front = (queue->front + 1) % queue->capacity;
  queue->size = queue->size - 1;
  return item;
}

int front(struct queue *queue){
  if (isEmpty(queue)) return INT_MIN;
  return queue->array[queue->front];
}

int rear(struct queue *queue){
  if (isEmpty(queue)) return INT_MIN;
  return queue->array[queue->rear];
}

int main(){
  struct queue *queue = createQueue(10);

  enqueue(queue, 10);
  enqueue(queue, 20);
  enqueue(queue, 30);
  enqueue(queue, 40);

  printf("%d kuyruktan cikarildi\n", dequeue(queue));

  printf("ondeki %d\n", front(queue));
  printf("arkadaki %d\n", rear(queue));

  return 0;
}