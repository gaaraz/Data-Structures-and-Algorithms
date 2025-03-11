#include <stdio.h>

int f(int n){
	if(n == 1) return 1;
	return (f(n-1) + 1) * 2;
}

int main()
{
	int n;
	scanf("%d", &n);
	int ret = f(n);
	printf("%d\n", ret);
	return 0;
}
