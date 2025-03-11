#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
	int data;
	struct Node* next;
} Node;

Node* initNode(int val){
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = val;
	node->next = node;
	return node;
}

void destory(Node* head){
	if(head == NULL) return;

	Node* p=head->next;
    do{
        free(p);
        p = p->next;
    }while(p != head->next);

	return;
}

Node* insert(Node* head, int pos, int val){
	Node* node = initNode(val);
	if(head == NULL){
		return node;
	}
	Node* p = head;
	for(int i=0;i<pos;i++){
		p = p->next;
	}
	if(p == head){
		head = node;
	}
	node->next = p->next;
	p->next = node;
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
	Node* p=head->next;
	do{
		printf("%3d", n);
		printf("  ");
	    n++;
 		p = p->next;
	}while(p != head->next);

	printf("\n");
	Node* q=head->next;
	do{
    	printf("%3d", q->data);
	    printf("->");
        q = q->next;
	}while(q != head->next);

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
	int val;
	while(~scanf("%d", &val)){
		if(contain(head,val)){
			printf("found it");
		}else{
			printf("not found");
		}
	}
	destory(head);
	return 0;
}
