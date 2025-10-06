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
    if (k->rear == k->size -1)
        return 1;
    return 0;
    
}
int isEmpty(queue* k){
    if (k->rear == k->front)
        return 1;
    return 0;
    
}

void enqueue(queue* k,int val ){
    if(!isFull(k)){
        k->rear += 1;
        (k->arr)[k->rear] = val;
    }
    else
        printf("Overflow!\n");
    

}
void dequeue(queue* k){
    if (!isEmpty(k))
        k->front += 1;
    else
        printf("Underflow!\n");
}

void printQueue(queue k){
    for (int i = k.front+1; i <= k.rear; i++)
    {
        printf("%d ",(k.arr)[i]);
    }
    printf("\n");

}

int main(){

    queue k;
    k.size = 3;
    k.front = k.rear = -1;
    k.arr = (int*)malloc(k.size * sizeof(int));

    dequeue(&k);

    printQueue(k);

    enqueue(&k,12);
    enqueue(&k,99);
    enqueue(&k,199);

    printQueue(k);

    dequeue(&k);

    printQueue(k);
    return 0;
}
