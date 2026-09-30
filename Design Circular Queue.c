typedef struct {
    int *arr;
    int front;
    int size;
    int capacity;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {

    MyCircularQueue* queue = malloc(sizeof(MyCircularQueue));
    queue->arr = malloc(sizeof(int) * k);
    queue->front = queue->size = 0;
    queue->capacity = k;
    return queue;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(obj->size == obj->capacity)
        return false;

    obj->arr[(obj->front + obj->size) % obj->capacity] = value;
    obj->size += 1;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(obj->size == 0)
        return false;

    if(obj->size == 1)
        obj->front = 0;
    else 
        obj->front = (obj->front + 1) % obj->capacity;

    obj->size--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(obj->size == 0) 
        return -1;
    return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(obj->size == 0) 
        return -1;
    return obj->arr[(obj->front + obj->size - 1) % obj->capacity];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size == obj->capacity;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
