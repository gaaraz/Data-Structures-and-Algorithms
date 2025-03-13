/*************************************************************************
	> File Name: queue_vector.c
	> Author: 
	> Mail: 
	> Created Time: Tue Jun 11 18:40:25 2024
 ************************************************************************/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef struct Vector{
    int* data;
    int size;
} Vector;

Vector* initVector(int n){
    Vector* v = (Vector*)malloc(sizeof(Vector));
    v->size = n;
    v->data = (int*)malloc(n * sizeof(int));
    return v;
}

void destoryVector(Vector* v){
    if(v == NULL) return;
    free(v->data);
    free(v);
    return;
}

int vectorSeek(Vector* v, int pos){
    if(pos < 0 || pos > v->size) return -1;
    return v->data[pos];
}

int insertVector(Vector* v, int pos, int val){
    if(pos < 0 || pos > v->size) return -1;
    v->data[pos] = val;
    return 1;
}

typedef struct Queue{
    Vector* data;
    int size;
    int head;
    int tail;
    int count;
} Queue;

Queue* initQueue(int n){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = initVector(n);
    q->size = n;
    q->head = 0;
    q->tail = 0;
    q->count = 0;
    return q;
}

int empty(Queue* q){
    return q->count == 0;
}

int push(Queue* q, int val){
    if(q->count == q->size) return 0;
    insertVector(q->data, q->tail, val);
    q->tail += 1;
    q->tail %= q->size;
    //if(q->tail == q->size) q->tail = 0;
    q->count += 1;
    return 1;
}

int front(Queue* q){
    return vectorSeek(q->data, q->head);
    //return q->data[q->head];
}

int pop(Queue* q){
    if(empty(q)) return 0;
    q->head += 1;
    q->head %= q->size;
    q->count -= 1;
    return 1;
}

void destoryQueue(Queue* q){
    if(q == NULL) return;
    destoryVector(q->data);
    free(q);
}

void outputQueue(Queue* q){
    printf("Queue : ");
    for(int i=0;i<q->count; i++){
        printf("%4d", vectorSeek(q->data, (q->head + i)%(q->size)));
    }
    printf("\n\n");
    return;
}

int main(){
    srand(time(0));
    Queue* q = initQueue(5);
    for(int i=0; i<10; i++){
        int op = rand()%5;
        int val;
        switch(op){
            case 0:
                printf("front of queue : %d\n", front(q));
                pop(q);
                break;
            case 1:
            case 2:
            case 3:
            case 4:
                val = rand()%100;
                printf("push %d to queue\n", val);
                push(q, val);
                break;
        }
        outputQueue(q);
    }

    return 0;
}
