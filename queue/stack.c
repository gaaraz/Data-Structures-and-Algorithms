/*************************************************************************
	> File Name: stack.c
	> Author: 
	> Mail: 
	> Created Time: Fri Jun 14 03:04:27 2024
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Stack{
    int* data;
    int size;
    int top;
} Stack;

Stack* initStack(int n){
    Stack* p = (Stack*)malloc(sizeof(Stack));
    p->data = (int*) malloc(sizeof(int) * n);
    p->size = n;
    p->top = -1;
    return p;
}

void destoryStack(Stack* s){
    if(s == NULL) return;
    free(s->data);
    free(s);
    return;
}

int empty(Stack* s){
    return s->top == -1;
}

int top(Stack* s){
    if(empty(s)) return -1;
    return s->data[s->top];
}

int push(Stack* s, int val){
    if(s->top+1 == s->size) return 0;
    s->top += 1;
    s->data[s->top] = val;
    return 1;
}

int pop(Stack* s){
    if(empty(s)) return 0;
    s->top -= 1;
    return 1;
}

void outputStack(Stack* s){
    printf("Stack : ");
    for(int i=s->top; i>=0; i--){
        printf("%4d", s->data[i]);
    }
    printf("\n\n");
}


int main(){
    srand(time(0));
    Stack* s = initStack(5);
    for(int i=0; i<10; i++){
        int op = rand()%3;
        int val;
        switch(op){
            case 0:
                printf("pop stack, item = %d\n", top(s));
                pop(s);
                break;
            case 1:
            case 2:
                val = rand()%100;
                printf("push stack, item = %d\n", val);
                push(s, val);
                break;
        }
        outputStack(s);
    }
    return 0;
}
