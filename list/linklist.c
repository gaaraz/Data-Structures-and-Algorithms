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
	node->next = NULL;
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
	// 虚拟头节点,方便操作
    Node new_head,*p = &new_head;
	Node* node = initNode(val);
	new_head.next = head;
	for(int i=0;i<pos;i++){
		p = p->next;
	}
	node->next = p->next;
	p->next = node;
	return new_head.next;
}

Node* insertWithOutHead(Node* head, int pos, int val){
	Node* node = initNode(val);
	if(pos == 0){
		node->next = head;
		return node;
	}
	Node* p = head;
	for(int i=1;i<pos;i++){
		p = p->next;
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
	for(Node* p=head; p; p=p->next){
		printf("%3d", n);
		printf("  ");
		n++;
	}
	printf("\n");
	for(Node* p=head; p; p=p->next){
		printf("%3d", p->data);
		printf("->");
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
