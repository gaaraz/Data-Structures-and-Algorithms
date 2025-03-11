#include <stdio.h>

int arr[10];
void print_arr(int i){
	int j;
	for(j=0;j<=i;j++){
		if(j) printf(" ");
		printf("%d", arr[j]);
	}
	printf("\n");
}

void f(int i, int j, int n){
	if (j>n) return;
	int m;
	for(m=j;m<=n;m++){
		arr[i]=m;
		print_arr(i);
		f(i+1, m+1, n);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	f(0, 1, n);
	return 0;
}
