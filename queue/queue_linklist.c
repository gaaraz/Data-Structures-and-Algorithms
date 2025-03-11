/*************************************************************************
	> File Name: queue_linklist.c
	> Author: 
	> Mail: 
	> Created Time: Thu Jun 13 02:07:31 2024
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* initNode(int val){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->next = NULL;
    return node;
}




typedef struct LinkList{
    Node* head;
    Node* tail;
} LinkList;

LinkList* initLinkList(){
    LinkList* linkList = (LinkList*)malloc(sizeof(linkList));
    linkList->head = initNode(0);
    linkList->tail = linkList->head;
    return linkList;
}

void destoryLinkList(LinkList* linkList){
    Node* p = linkList->head->next;
    Node* q;
    while(p){
        q = p->next;
        free(p);
        p = q;
    }
    free(linkList);
    return;
}
int getLinkListHead(LinkList* linkList){
    if(linkList->head->next == NULL) return 0;
    return linkList->head->next->data;
}    

int insertTail(LinkList* linkList, int val){
    Node* node = initNode(val);
    linkList->tail->next = node;
    linkList->tail = node;
    return 1;
}

int emptyList(LinkList* linkList){
    return linkList->head->next == NULL;
}

int eraseHead(LinkList* linkList){
    if(emptyList(linkList)) return 0;
    Node* p = linkList->head->next;
    linkList->head->next = p->next;
    if(p == linkList->tail){
        linkList->tail = linkList->head;
    }
    free(p);
    return 1;
}




typedef struct Queue{
    LinkList* list;
    int count;
} Queue;

Queue* initQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->list = initLinkList();
    q->count = 0;
    return q;
}

void destoryQueue(Queue* q){
    if(q == NULL) return;
    destoryLinkList(q->list);
    free(q);
    return;
}

int empty(Queue* q){
    return q->count == 0;
}

int front(Queue* q){
    if(empty(q)) return 0;
    return getLinkListHead(q->list);
}

int push(Queue* q, int val){
    insertTail(q->list, val);
    q->count += 1;
    return 1;
}

int pop(Queue* q){
    eraseHead(q->list);
    q->count -= 1;
    return 1;
}

void outputQueue(Queue* q){
    printf("Queue : ");
    Node* p = q->list->head->next;
    for(int i=0;i < q->count; i++){
        printf("%4d", p->data);
        p = p->next;
    }
    printf("\n\n");
    return;
}


int main(){
    srand(time(0));
    Queue* q = initQueue();
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

