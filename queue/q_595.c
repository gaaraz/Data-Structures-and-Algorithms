/*************************************************************************
	> File Name: q_595.c
	> Author: 
	> Mail: 
	> Created Time: Thu Jun 20 04:43:40 2024
 ************************************************************************/

#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n;
	scanf("%d", &n);
	char** arr = (char**)malloc(sizeof(char*) * n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = (char*)malloc(6 * sizeof(char));
		scanf("%s", arr[i]);
	}
	char* target = (char*)malloc(6 * sizeof(char));
	scanf("%s", target);
	
	char** stack = (char**)malloc(sizeof(char*) * n);
	int top = 0;
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		stack[top] = arr[i];
		if (strcmp(target, arr[i]) == 0) {
			flag = 1;
		}
		if (strcmp("return", arr[i]) == 0) {
			top--;
		}
		else
		{
			top++;
		}
	}
	if (flag)
	{
		for (int i = 0; i < top; i++) {
			printf("%s", stack[i]);
			if (i < top-1)
			{
				printf("%s", "->");
			}
		}
	}
	else 
	{
		printf("%s", "NOT REFERENCED");
	}
}
