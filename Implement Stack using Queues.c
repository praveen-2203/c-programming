#include <stdbool.h>
#include <stdlib.h>

// --- Standard Queue Implementation ---
typedef struct {
    int* data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (int*)malloc(capacity * sizeof(int));
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    q->capacity = capacity;
    return q;
}

void enqueue(Queue* q, int val) {
    q->data[q->rear] = val;
    q->rear = (q->rear + 1) % q->capacity;
    q->size++;
}

int dequeue(Queue* q) {
    int val = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return val;
}

int peek(Queue* q) {
    return q->data[q->front];
}

bool isQueueEmpty(Queue* q) {
    return q->size == 0;
}

void freeQueue(Queue* q) {
    free(q->data);
    free(q);
}

// --- MyStack Implementation (Using One Queue) ---
typedef struct {
    Queue* q;
} MyStack;

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    // Constraints state at most 100 calls total
    stack->q = createQueue(105); 
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    int current_size = obj->q->size;
    
    // 1. Add new element to the back of the queue
    enqueue(obj->q, x);
    
    // 2. Rotate the queue so the new element reaches the front
    for (int i = 0; i < current_size; i++) {
        enqueue(obj->q, dequeue(obj->q));
    }
}

int myStackPop(MyStack* obj) {
    // The top element is already at the front of the queue
    return dequeue(obj->q);
}

int myStackTop(MyStack* obj) {
    // Return the front element without removing it
    return peek(obj->q);
}

bool myStackEmpty(MyStack* obj) {
    return isQueueEmpty(obj->q);
}

void myStackFree(MyStack* obj) {
    freeQueue(obj->q);
    free(obj);
}
