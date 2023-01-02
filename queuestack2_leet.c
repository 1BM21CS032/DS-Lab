#define SIZE 100
typedef struct {
    int stack[SIZE];
    int top;
    int size;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *temp = (MyQueue *)malloc(sizeof(MyQueue));
    temp->top=0;
    temp->size=0;
    return temp;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->size++;
    obj->stack[obj->top++]=x;
}

int myQueuePop(MyQueue* obj) {
    obj->size--;
    return obj->stack[obj->top--];
}

int myQueuePeek(MyQueue* obj) {
    return obj->stack[0];
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
