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
    int i = 0;
    char *p = src;
    printf("p = %s\n", p);

    while (*p != '\0') {
        p++;
        i++;
    }

    char *q = malloc(i * sizeof(char));
    char *des = q;

    while (i>0) {
        i--;
        p--;
        printf("p = %c\n", *p);
        *q = *p;
        printf("q = %c\n", *q);
        q++;
    }
    q++;
    *q = '\0';

    return des;
}

int main()
{
    char *s = "hello world!";
    char *d = reverseString(s);

    printf("d = %s\n", d);
}
