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

int * countBits(int num, int *returnSize) {

}

int main()
{
    int num = 5;
    int returnSize[num];
    
    int *p;
    p = countBits(num, returnSize);

    return 0;
}
