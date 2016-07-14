/*************************************************************************
	> File Name: two_Sum.c
	> Author: 
	> Mail: 
	> Created Time: 2016年07月13日 星期三 01时31分10秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


typedef struct linkedListNode *plistNode;
typedef struct linkedListNode {
    int index;
    plistNode next;
}listNode;

int *twoSum(int nums[], int numberSize, int target)
{
    int index = 0;
    /*hash表大小要靠试的 :)*/
    int hash_size = 43853;
    int finded = 0;

    plistNode hashTable = (plistNode) malloc (sizeof(listNode) * hash_size);
    if (!hashTable) {
        return NULL;
    }
    
    /*Init hashTable*/
    for (index=0; index<hash_size; index++) {
        hashTable[index].index = -1;
        hashTable[index].next = NULL;
    }

    /*Assign nums into hashTable*/
    for (index=0; index<numberSize; index++) {
        int number = ((nums[index] + hash_size) % hash_size);
        if (-1 == hashTable[number].index) {
            hashTable[number].index = index;
        } else {
            listNode *tail = hashTable[number].next;
            tail = (plistNode) malloc (sizeof(listNode));
            /* 
            * 这里有个大坑, tail一定要先声明然后再分配内存 如果反过来会报segment fault */
            /* 因为先分配内存的话, 
            *  listNode *tail = (plistNode) malloc (sizeof(listNode));
            *  #(gdb) p tail
            *  #$30 = (listNode *) 0x602010
            *  分配以后
            *  assert(tail);
            *  tail = hashTable[number].next;
            *  这句是赋值操作,执行完以后tail就变成hashTable[number].next里的内容了
            *  (gdb) p hashTable[number] 
            *  $32 = {index = 0, next = 0x0}
            *  (gdb) p hashTable[number].next 
            *  $33 = (plistNode) 0x0
            *
            * */
            tail->index = index;
            tail->next = hashTable[number].next;
            hashTable[number].next = tail;
        }
    }


    int *ret = (int *) malloc (sizeof(int)*2);
    /*search*/
    for (index=0; index<numberSize; index++) {
        int number = nums[index];
        int find = ((target - number + hash_size) % hash_size);
        if (find == number) {
            if (hashTable[find].next != NULL) {
                finded = 1;
                ret[0] = index;
                ret[1] = hashTable[find].next->index;
                goto out;
            }
            continue;

        }
        if (hashTable[find].index != -1) {
            finded = 1;
            ret[0] = index;
            ret[1] = hashTable[find].index;
            goto out;
        }
    }
out:
    if (finded == 1) {
        return ret;
    }
    return NULL;
}

int main()
{
    int array[] = {230,863,916,585,981,404,316,785,88,12,70,435,384,778,887,755,740,    \
                   337,86,92,325,422,815,650,920,125,277,336,221,847,168,23,677,61,400, \
                   136,874,363,394,199,863,997,794,587,124,321,212,957,764,173,314,422, \
                   927,783,930,282,306,506,44,926,691,568,68,730,933,737,531,180,414,   \
                   751,28,546,60,371,493,370,527,387,43,541,13,457,328,227,652,365,430, \
                   803,59,858,538,427,583,368,375,173,809,896,370,789};
    size_t n = sizeof(array)/sizeof(array[0]);
    int target = 542;
    int i;

    printf("array: ");
    for (i=0; i<n; i++) {
        printf("%d ", array[i]);
    }

    puts("");
    printf("target: %d\n", target);

    int *result = twoSum(array, n, target);
    if (result != NULL) {
        printf("index: %d %d\n", result[0], result[1]);
    }
    return 0;
}
