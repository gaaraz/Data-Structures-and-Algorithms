/*************************************************************************
	> File Name: leetcode_206.c
	> Author: 
	> Mail: 
	> Created Time: Mon Jun  3 01:04:02 2024
 ************************************************************************/

#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* newHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    newHead->next = NULL;
    struct ListNode* p = head;
    struct ListNode* q;
    while(p != NULL){
        q = p->next;
        p->next = newHead->next;
        newHead->next = p;
        p = q;
    }
    return newHead->next;
}

struct ListNode* initNode(int val){
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct List));
    node->val = val;
    node->next = NULL;
}

struct ListNode* insertNode(, int val){
}

bool hasCycle(struct ListNode *head) {
    ListNode* fast = head, slow = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
}

int main(){

    return 0;
}
