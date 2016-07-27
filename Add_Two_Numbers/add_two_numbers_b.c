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

struct ListNode *addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int dump = 0;
    int i = 0;
    if (!l1 || !l2) {
        return NULL;
    }

    /*保留表头,使用ll1,ll2作为游标*/
    struct ListNode *ll1 = l1;
    struct ListNode *ll2 = l2;

    struct ListNode *resNode = (struct ListNode *) malloc (sizeof(struct ListNode));
    if (!resNode) {
        return NULL;
    }

    struct ListNode *p = resNode;

    while (ll1 || ll2) {
        struct ListNode *pListNode = (struct ListNode *) malloc (sizeof(struct ListNode));
        if (!pListNode) {
            return NULL;
        }
        pListNode->val = dump + (ll1? ll1->val : 0) + (ll2? ll2->val : 0);
        dump = pListNode->val / 10;
        pListNode->val  %= 10;
        pListNode->next = NULL;
        p->next = pListNode;
        p = p->next;

        if (ll1) {
            ll1 = ll1->next;
        }

        if (ll2) {
            ll2 = ll2->next;
        }
        
    }

    if (dump != 0) {
        struct ListNode *pListNode = (struct ListNode *) malloc (sizeof(struct ListNode));
        if (!pListNode) {
            return NULL;
        }

        pListNode->val = dump;
        p->next = pListNode;
        p = p->next;
    }

    return resNode->next;
}

#define LENGTH 9
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
    int Array1[] = {0,5,3,0,3,2,2,0,2};
    int Array2[] = {8,0,2,8,9,6,2,1,9};
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

    tmp = res;

    i = 0;
    while (tmp) {
        printf("after calculating: \n");
        printf("res[%d] = %d\n", i, tmp->val);
        i++;
        tmp = tmp->next;
    }
    return 0;

}
