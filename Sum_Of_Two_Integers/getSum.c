/*************************************************************************
	> File Name: getSum.c
	> Author: 
	> Mail: 
	> Created Time: 2016年08月09日 星期二 22时43分48秒
 ************************************************************************/

#include<stdio.h>


int getSum(int a, int b)
{
    /* 
     * a^b 表示a+b相加的结果,但是忽略了进位的情况
     * a&b 表示a与b相加进位的位置
     * 比如 0110 1101两个数 
     * 0110 ^ 1101 = 1011
     * 0110 & 1101 = 0100
     * 但是进位位置为1所在的位置左移一位,因此进位位置为 0100 << 1
     * 剩下的步骤为把进位所在的位置加入 a^b 的结果中
     * 1011 ^ 1000 = 0011
     * 1011 & 1000 = 1000 << 2 -> 10000
     *
     * 0011 ^ 10000 = 10011
     * 0011 & 10000 = 00000
    */

    int sum = a^b;
    int carry = ((a&b) << 1);

//    printf("carry = %d\n", carry);
//    printf("sum = %d\n", sum);
    int tmp;
    while (carry) {
        tmp = sum ^ carry;
        carry = ((sum & carry)<<1);
        sum = tmp;
    }

    printf("sum = %d\n",sum);
    return sum;

}


int main()
{
    return getSum(6,139);
}
