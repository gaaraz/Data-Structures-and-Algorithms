#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
	int data;
	struct Node* next;
    struct Node* pre;
} Node;

Node* initNode(int val){
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = val;
	node->next = NULL;
    node->pre = NULL;
	return node;
}

void destory(Node* head){
	if(head == NULL) return;
	for(Node* p=head,*q; p; p=q){
		q = p->next;
		free(p);
	}
	return;
}

Node* insert(Node* head, int pos, int val){
        Node* node = initNode(val);
        if(pos == 0){
            node->next = head;
            if(head != NULL){
                head->pre = node;
            }
            return node;
        }
        Node* p = head;
        for(int i=1;i<pos;i++){
            p = p->next;
        }
        Node* next = p->next;
        node->next = next;
        node->pre = p;
        p->next = node;
        if(next != NULL){
            next->pre=node;
        }
        return head;
}

Node* removeOne(Node* head, int pos){
	Node* p = head;
    for(int i=1;i<pos;i++){
    	p = p->next;
    }
	Node* curr = p->next;
	p->next=curr->next;
	free(curr);
	return head;
}

int contain(Node* head, int val){
	Node* p = head;
	while(p){
		if(p->data == val) return 1;
		p = p->next;
	}
	return 0;
}

void outputLinklist(Node* head){
	int n = 0;
	for(Node* p=head; p; p=p->next){
		printf("%3d", n);
		printf("  ");
		n++;
	}
	printf("\n");
    Node* p = head;
	while(p != NULL){
		printf("%3d", p->data);
		printf("->");
        p = p->next;
	}
	printf("\n");
    Node* q = head;
    for(int i=1;i<n;i++){
        q = q->next;
    }
    while(q != NULL){ 
		printf("%3d", q->data);
		printf("->");
        q = q->pre;
    }
    printf("\n");
	return;
}

int main(){
	srand(time(0));
	Node* head = NULL;
	for(int i=0;i<10;i++){
		int pos = rand()%(i+1), val = rand()%100;
		printf("insert %d at %d to linklist\n", val, pos);
		head = insert(head, pos, val);
		outputLinklist(head);
	}
	destory(head);
	return 0;
}
