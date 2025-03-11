#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct vector{
	int size;
	int count;
	int* data;
} vector;

vector* initVector(int n){
	vector* p = (vector*)malloc(sizeof(vector));
	p->size = n;
	p->count = 0;
	p->data = (int*)malloc(n * sizeof(int));
	return p;
}

void destory(vector* v){
	if(v == NULL) return;
	free(v->data);
	free(v);
	return;
}

int expend(vector* v){
	if(v == NULL) return 0;
	int* p = (int*)realloc(v->data, sizeof(int) * v->size * 2);
	if(p == NULL) return 0;
	v->data = p;
	v->size = v->size * 2;
	return 1;
}

int insert(vector* v, int pos, int val){
	if(pos < 0 || pos > v->count) return 0;
	if(v->size == v->count && !expend(v)) return 0;

	for(int i=v->count - 1; i>=pos; i--){
		v->data[i+1] = v->data[i];
	}
	v->data[pos] = val;
	v->count += 1;
	return 1;
}

int removeItem(vector* v, int pos){
	if(pos < 0 || pos >= v->count) return 0;
	for(int i=pos+1;i<v->count;i++){
		v->data[i-1]=v->data[i];
	}
	v->count -= 1;
	return 1;
}

void outputVector(vector* v){
	int len = 0;
	for(int i=0;i<v->size;i++){
		len += printf("%3d", i);
	}
	printf("\n");
	for(int i=0;i<len;i++){
		printf("-");
	}
	printf("\n");
	for(int i=0;i<v->count;i++){
		printf("%3d", v->data[i]);
	}
	printf("\n\n\n");
	return;
}

int main(){
	srand(time(0));
	vector* v = initVector(2);
	for(int i=0;i<20;i++){
		int op = rand() % 4;
		int pos,val;
		switch(op){
			case 0:
			case 1:
			case 2:
				pos = rand()%(v->count+1);
				val = rand()%100;
				printf("insert %d at %d to vector = %d\n", val, pos, insert(v, pos,val));
				break;
			case 3:
				pos = rand()%(v->count+1);
				printf("remove item at %d in vector = %d\n", pos, removeItem(v, pos));
				break;
		}
		outputVector(v);
	}
	destory(v);
}
