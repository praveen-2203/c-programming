#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int* s1;       // Input stack
    int* s2;       // Output stack
    int top1;      // Top pointer for stack 1
    int top2;      // Top pointer for stack 2
    int capacity;  // Max size of stacks
} MyQueue;

/** Initializes the queue object. */
MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->capacity = 100; // Max 100 calls based on constraints
    obj->s1 = (int*)malloc(sizeof(int) * obj->capacity);
    obj->s2 = (int*)malloc(sizeof(int) * obj->capacity);
    obj->top1 = -1;
    obj->top2 = -1;
    return obj;
}

/** Pushes element x to the back of the queue. */
void myQueuePush(MyQueue* obj, int x) {
    obj->s1[++(obj->top1)] = x;
}

/** Removes the element from the front of the queue and returns it. */
int myQueuePop(MyQueue* obj) {
    // If output stack is empty, transfer all elements from input stack
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->s2[++(obj->top2)] = obj->s1[(obj->top1)--];
        }
    }
    return obj->s2[(obj->top2)--];
}

/** Returns the element at the front of the queue. */
int myQueuePeek(MyQueue* obj) {
    // If output stack is empty, transfer all elements from input stack
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->s2[++(obj->top2)] = obj->s1[(obj->top1)--];
        }
    }
    return obj->s2[obj->top2];
}

/** Returns true if the queue is empty, false otherwise. */
bool myQueueEmpty(MyQueue* obj) {
    return (obj->top1 == -1 && obj->top2 == -1);
}

/** Deallocates the memory allocated for the queue. */
void myQueueFree(MyQueue* obj) {
    free(obj->s1);
    free(obj->s2);
    free(obj);
}
