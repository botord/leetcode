/*************************************************************************
	> File Name: myAtoi.c
	> Author: 
	> Mail: 
	> Created Time: 2016年08月15日 星期一 16时43分29秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int myAtoi(char* str) {
    if (!str) {
        return 0;
    }
    int len = strlen(str);
    long long ret = 0;
    int i = 0;
    int minus = 0;
    while (str[i] == ' ') {
        i++;
    }

    if (str[i] == '+' || str[i] == '-') {
        if ((str[i]) == '-') {
            minus = 1;
            i++;
        } else if (str[i] == '+') {
            i++;
        } else {
            return 0;
        }
    }

    for (; i<len; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            ret = (str[i]-'0') + ret * 10;
            if (ret >= INT_MAX) {
                if (minus) {
                    ret *= (-1);
                    if (ret <= INT_MIN)
                        return INT_MIN;
                    else 
                        return ret;
                }
                return INT_MAX;
            }
        } else {
            break;
        }
    }
    if (minus) {
        ret = 0 - ret;
    }
    return ret;
} 


int main()
{
    char integer[20] = "2147483648";

    int ret = myAtoi(integer);

    printf("ret of integer is %d\n", ret);
}
