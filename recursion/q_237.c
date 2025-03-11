#include <stdio.h>

int arr[10],vis[10]={0};

void print_arr(int n){
	int i;
	for(i=0;i<n;i++){
		if(i){
			printf(" ");
		}
		printf("%d", arr[i]);
	}
	printf("\n");
}

void f(int i, int n){
	if(i == n){
		print_arr(n);
		return;
	}
	int k;
	for(k=1;k<=n;k++){
		if(vis[k]){
			continue;
		}
		arr[i]=k;
		vis[k]=k;
		f(i+1, n);
		vis[k]=0;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	f(0, n);
	return 0;
}
