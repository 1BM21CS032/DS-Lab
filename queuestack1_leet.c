#define  STACK_SIZE  100

typedef struct {
    int Stack[STACK_SIZE];
    int Front;
    int Rear;
    int size;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *Queue = malloc(sizeof(MyQueue));
    Queue->Front = 0;
    Queue->Rear  = 0;
    Queue->size  = 0;
    return Queue;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->size++;
    obj->Stack[obj->Rear] = x;
    obj->Rear = ((obj->Rear + 1) % STACK_SIZE);
}

int myQueuePop(MyQueue* obj) {
    obj->size--;
    obj->Front = (obj->Front + 1) % STACK_SIZE;
    return obj->Stack[(obj->Front-1) % STACK_SIZE]; 
}

int myQueuePeek(MyQueue* obj) {
    return (obj->Stack[obj->Front]) % STACK_SIZE;
}

bool myQueueEmpty(MyQueue* obj) {
    if(obj->size == 0)
        return true;
    else
        return false;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
