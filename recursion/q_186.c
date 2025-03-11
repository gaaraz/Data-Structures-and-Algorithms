#include <stdio.h>

int f(int i, int* arr, int n){
	if(i>=n) return 0;
	return f(i+arr[i], arr, n)+1;
}

int main(){
	int n,i;
	scanf("%d", &n);
	int arr[n];
	for(i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}

	int ret = f(0, arr, n);
	printf("%d\n", ret);
	return 0;
}
