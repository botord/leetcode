/*************************************************************************
	> File Name: count_Bits.c
	> Author: 
	> Mail: 
	> Created Time: 2016年08月10日 星期三 16时11分26秒
 ************************************************************************/
/*
Given a non negative integer number num. 
For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their
binary representation and return them as an array.

Example:
    For num = 5 you should return [0,1,1,2,1,2].

Follow up:
    It is very easy to come up with a solution with run time O(n*sizeof(integer)).
    But can you do it in linear time O(n) /possibly in a single pass?
    Space complexity should be O(n).
    Can you do it like a boss? Do it without using any builtin function like 
    __builtin_popcount in c++ or in any other language.

*/

#include<stdio.h>
#include<stdlib.h>

int *countBits(int num, int *returnSize) {
    int *res = (int *) malloc ((num+1) * sizeof(int));
    int i;

    *returnSize = num+1;

    res[0] = 0;
    for (i=1; i<=num; i++) {
        res[i] = res[i>>1] + (i&1);
    }

    return res;
}

int *countBits_b (int num, int *returnSize) {
    int *res = (int *) calloc (num+1, sizeof (int));
    unsigned int i = 0;
    unsigned int cursor = 0;
    unsigned int power = 1;
    
    *returnSize = num + 1;
    res[0] = 0;
    for (i=1; i<=num; i++) {
        if (i == power) {
            power <<= 1;
            cursor = 1;
            res[i] = 1;
        } else {
            res[i] = res[cursor++] + 1;
        }
    }

    return res;
}

int main()
{
    int num = 16;
    int returnSize;
    int i;
    
    int *p;
    p = countBits_b(num, &returnSize);

    for (i=0; i<returnSize; i++) {
        printf("%d\n", *(p+i));
    }

    printf("returnSize = %d\n", returnSize);

    return 0;
}
