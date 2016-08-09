/*************************************************************************
	> File Name: reverseString.c
	> Author: 
	> Mail: 
	> Created Time: 2016年08月09日 星期二 09时04分45秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

char *reverseString(char *src) 
{
    printf("src = %s\n", src);
    int i, j;
    i = strlen(src);
    int len = i/2;
    char tmp;
    
    //swap
    for (j = 0; j < len; j++,i--) {
        tmp = src[j];
        src[j] = src[i-1];
        src[i-1] = tmp;
    }

    return src;
}


int main()
{
    char s[] = "A man \
                a plan \
                a cameo \
                Zena";
    char *d = reverseString(s);

    printf("d = %s\n", d);

    return 0;
}
