/*************************************************************************
	> File Name: leetcode_622.c
	> Author: 
	> Mail: 
	> Created Time: Tue Mar 18 16:53:50 2025
 ************************************************************************/

#include<stdio.h>

typedef struct Node{
    int data;
    struct Node* node;
} Node;


typedef struct {
    int size;
    int count;
    Node* head;
    Node* tail;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* queue = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    Node* head = (Node*)malloc(sizeof(Node));
    Node* tail = head;
    for(int i=1; i<k; i++){
        tail->next = (Node*)malloc(sizeof(Node));
        tail = tail->next;
    }
    tail->next = head;

    queue->head = head;
    queue->tail = tail;

    queue->size = k;
    queue->count = 0;
    
    return queue;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull()){
        return false;
    }
    obj->tail = obj->tail->next;
    obj->tail->data = value;
    count += 1;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty()){
        return false;
    }
    obj->head = obj->head->next;
    count -= 1;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty()){
        return -1;
    }
    return obj->head->data;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty()){
        return -1;
    }
    return obj->tail->data;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->count == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->count == obj->size;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    if(!myCircularQueueIsEmpty(obj)){
        Node *p = obj->head, *q;
        for(int i=0; i<obj->count; i++){
            q = p->next;
            free(p);
            p=q;
        }
    }
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


