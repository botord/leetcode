/*************************************************************************
	> File Name: add_two_numbers.c
	> Author: 
	> Mail: 
	> Created Time: 2016年07月18日 星期一 22时15分37秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct linkedListNode *plistNode;

typedef struct linkedListNode {
    unsigned int data;
    plistNode next;
}ListNode;

struct ListNode *addTwoNumbers(struct linkedListNode *l1, struct linkedListNode *l2)
{
    int i = 0;
    if (!l1 || !l2) {
        return NULL;
    }
    /*不破坏源链表*/
    ListNode *ll1 = l1;
    ListNode *ll2 = l2;
    ListNode *listnode1 = (ListNode *)malloc(sizeof(ListNode));
    if (!listnode1) {
        return NULL;
    }
    ListNode *h1 = ll1;
    ListNode *h2 = ll2;
    listnode1->data = ll1->data;
    listnode1->next = NULL;

    while (ll1) {
        ListNode *r1= (ListNode *) malloc (sizeof(ListNode));
        if (!r1) {
            return NULL;
        }
        r1->data = ll1->data;
        r1->next = listnode1->next;
        listnode1->next = r1;
        ll1 = ll1->next;
    }
    
    ListNode *listnode2 = (ListNode *)malloc(sizeof(ListNode));
    if (!listnode1) {
        return NULL;
    }
    listnode2->data = ll2->data;
    listnode2->next = NULL;

    while (ll2) {
        ListNode *r2= (ListNode *) malloc (sizeof(ListNode));
        if (!r2) {
            return NULL;
        }

        r2->data = ll2->data;
        r2->next = listnode2->next;
        listnode2->next = r2;
        ll2 = ll2->next;
    } 
    ListNode *tmp;

    tmp = h1;
    i = 0;
    printf("reverse list1\n");
    while(tmp) {
        printf("tmp[%d] = %d\n", i, tmp->data);
        i++;
        tmp = tmp->next; 
    }

    h2->data = listnode2->data;
    h2->next = NULL;
    tmp = h2;
    i = 0;
    while(tmp) {
        printf("tmp[%d] = %d\n", i, tmp->data);
        i++;
        tmp = tmp->next; 
    }
    ListNode *res = (ListNode *)malloc(sizeof(ListNode));
    if (!res) {
        return NULL;
    }
    res->data = h1->data + h1->data;
    res->next = NULL;
    tmp = res;
    
    while (h1->next && h2->next) {
        ListNode *resNode = (ListNode *)malloc(sizeof(ListNode));
        if (!resNode) {
            return NULL;
        }
        resNode->data = h1->next->data + h2->next->data;
        resNode->next = NULL;
        tmp->next = resNode;
        tmp = tmp->next;
        h1 = h1->next;
        h2 = h2->next;
    }

    tmp = res;
    while(tmp) {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
    //return h1;
 
}

#define LENGTH 3
int main()
{
    int i = 0;
    int Array1[] = {2,4,3};
    int Array2[] = {5,6,4};


    ListNode *listnode1 = (ListNode *)calloc(1, sizeof(ListNode));
    ListNode *listnode2 = (ListNode *)calloc(1, sizeof(ListNode));

    if (!listnode1 || !listnode2) {
        return -1;
    }

    listnode1->data = 0;
    listnode2->data = 0;
    listnode1->next = NULL;
    listnode2->next = NULL;

    /*尾插法建立单链表*/
    ListNode *r = listnode1;
    for (i=0; i<LENGTH; i++) {
        ListNode *listnode = (ListNode *)malloc(sizeof(ListNode));
        listnode->data = Array1[i];
        listnode->next = r->next;
        r->next = listnode;
        r = listnode;
    }

    r = listnode2;
    for (i=0; i<LENGTH; i++) {
        ListNode *listnode = (ListNode *)malloc(sizeof(ListNode));
        listnode->data = Array2[i];
        listnode->next = r->next;
        r->next = listnode;
        r = listnode;
    }
    i = 0;
    ListNode *tmp = listnode1->next;
    printf("源链表1:\n");
    while(tmp) {
        printf("listnode1[%d] = %d\n", i, tmp->data);
        i++;
        tmp = tmp->next; 
    }
    tmp = listnode2->next;
    printf("源链表1:\n");

    while(tmp) {
        printf("listnode2[%d] = %d\n", i, tmp->data);
        i++;
        tmp = tmp->next; 
    }
    
    ListNode *res = addTwoNumbers(listnode1, listnode2);
    return 0;

}
