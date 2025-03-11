#include <stdio.h>

int arr[10];
void print_arr(int i){
    int j;
	for(j=0;j<i;j++){
        if(j) printf(" ");
     	printf("%d", arr[j]);
	}
	printf("\n");
}

void f(int i, int j, int n, int m){
	if(i==m){
		print_arr(m);
		return;
	}
	int k;
	for(k=j;k<=n && m-i-1 <= n-k;k++){
		arr[i]=k;
		f(i+1, k+1, n, m);
	}
}

int main(){
	int n,m;
	scanf("%d %d", &n, &m);
	f(0, 1, n, m);
	return 0;
}
