/*************************************************************************
	> File Name: add_two_numbers.c
	> Author: 
	> Mail: 
	> Created Time: 2016年07月18日 星期一 22时15分37秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode *addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int dump = 0;
    int i = 0;
    if (!l1 || !l2) {
        return NULL;
    }

    /*保留表头,使用ll1,ll2作为游标*/
    struct ListNode *ll1 = l1;
    struct ListNode *ll2 = l2;

    struct ListNode *listnode1 = (struct ListNode *) malloc (sizeof(struct ListNode));
    if (!listnode1) {
        return NULL;
    }
    struct ListNode *h1 = listnode1;
    listnode1->val = ll1->val;
    listnode1->next = NULL;
    ll1 = ll1->next;

    while (ll1) {
        struct ListNode *r1 = (struct ListNode *) malloc (sizeof(struct ListNode));
        if (!r1) {
            return NULL;
        }
        r1->val = ll1->val;
        r1->next = h1;
        h1 = r1;
        ll1 = ll1->next;
    }
    
    struct ListNode *listnode2 = (struct ListNode *) malloc (sizeof(struct ListNode));
    if (!listnode2) {
        return NULL;
    }
    listnode2->val = ll2->val;
    listnode2->next = NULL;
    ll2 = ll2->next;
    struct ListNode *h2 = listnode2;

    while (ll2) {
        struct ListNode *r2= (struct ListNode *) malloc (sizeof(struct ListNode));
        if (!r2) {
            return NULL;
        }
        r2->val = ll2->val;
        r2->next = h2;
        h2 = r2;
        ll2 = ll2->next;
    } 
    struct ListNode *tmp;

    ll1 = h1;
    ll2 = h2;
    struct ListNode *res = (struct ListNode *) malloc (sizeof(struct ListNode));
    if (!res) {
        return NULL;
    }
    ll1 = h1;
    ll2 = h2;
    res->val = h1->val + h2->val;
    if (res->val >= 10) {
        dump = 1;
        res->val -= 10;
    }
    res->next = NULL;
    tmp = res;

    ll1 = ll1->next;
    ll2 = ll2->next;

    while (ll1 && ll2) {
        struct ListNode *resNode = (struct ListNode *) malloc (sizeof(struct ListNode));
        if (!resNode) {
            return NULL;
        }
        resNode->val = ll1->val + ll2->val;
        if (dump) {
            resNode->val += 1;
            dump = 0;
        }
        if (resNode->val >= 10) {
            dump = 1;
            resNode->val -= 10;
        }
        resNode->next = NULL;
        tmp->next = resNode;
        tmp = tmp->next;
        ll1 = ll1->next;
        ll2 = ll2->next;
    }
    
    return res;
}
#define LENGTH 3
void print(int *Array)
{
    int i = 0;
    for (i=0; i<LENGTH; i++) {
        printf("%d ", Array[i]);
    }
}
int main()
{
    int i = 0;
    int Array1[] = {2,4,3};
    int Array2[] = {5,6,4};

    printf("Array1: ");
    print(Array1);
    puts("");
    printf("Array2: ");
    print(Array2);
    puts("");

    struct ListNode *listnode1 = (struct ListNode *) calloc (1, sizeof(struct ListNode));
    struct ListNode *listnode2 = (struct ListNode *) calloc (1, sizeof(struct ListNode));

    if (!listnode1 || !listnode2) {
        return -1;
    }

    listnode1->val = 0;
    listnode2->val = 0;
    listnode1->next = NULL;
    listnode2->next = NULL;

    /*尾插法建立单链表*/
    struct ListNode *r = listnode1;
    for (i=0; i<LENGTH; i++) {
        struct ListNode *listnode = (struct ListNode *) malloc (sizeof(struct ListNode));
        listnode->val = Array1[i];
        listnode->next = r->next;
        r->next = listnode;
        r = r->next;
    }

    r = listnode2;
    for (i=0; i<LENGTH; i++) {
        struct ListNode *listnode = (struct ListNode *) malloc (sizeof(struct ListNode));
        listnode->val = Array2[i];
        listnode->next = r->next;
        r->next = listnode;
        r = r->next;
    }

    i = 0;
    struct ListNode *tmp = listnode1->next;
    printf("源链表1:\n");
    while(tmp) {
        printf("listnode1[%d] = %d\n", i, tmp->val);
        i++;
        tmp = tmp->next; 
    }
    i = 0;
    tmp = listnode2->next;
    printf("源链表2:\n");

    while(tmp) {
        printf("listnode2[%d] = %d\n", i, tmp->val);
        i++;
        tmp = tmp->next; 
    }

    struct ListNode *res = addTwoNumbers(listnode1->next, listnode2->next);
    return 0;

}
