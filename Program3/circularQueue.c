#include<stdio.h>
#include<stdlib.h>

typedef struct Queue
{
    int size;
    int front;
    int rear;
    int* arr;
}queue;

int isFull(queue* k){
    if (k->rear == k->size -1 && k->front == -1)
        return 1;
    
    if ((k->rear +1 )%k->size == k->front)
        return 1;
    else
        return 0;
    
}
int isEmpty(queue* k){
    if (k->rear == (k->size -1) && k->front ==-1)
        return 0;
    
    if (k->rear == k->front)
        return 1;
    return 0;
    
}

void enqueue(queue* k,int val ){
    if(!isFull(k)){
        k->rear = (k->rear +1) % k->size;
        (k->arr)[k->rear] = val;
    }
    else
        printf("Overflow!\n");
}
void dequeue(queue* k){
    if (!isEmpty(k))
        k->front = (k->front +1)% (k->size);
    else
        printf("Underflow!\n");
}

void printQueue(queue k){
    int i = k.front;

    while (i!= k.rear)
    {
        printf("%d ",(k.arr)[(i+1)%k.size]);
        i = (i+1)%k.size;
    }
    
    printf("\n");

}

int main(){

    queue k;
    k.size = 3;
    k.front = k.rear = -1;
    k.arr = (int*)malloc(k.size * sizeof(int));

    dequeue(&k);

    // printQueue(k);

    enqueue(&k,10);
    enqueue(&k,100);
    enqueue(&k,200);

    printQueue(k);

    enqueue(&k,999);

    dequeue(&k);

    printQueue(k);

    dequeue(&k);
    dequeue(&k);
    
    dequeue(&k);




    return 0;
}
