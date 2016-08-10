/*************************************************************************
	> File Name: reverseWords.c
	> Author: 
	> Mail: 
	> Created Time: 2016年08月10日 星期三 09时30分05秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void reverseWord(char *s, int start, int end) {
    int length = end-start+1;
    int mid = length/2 + start;
    char tmp;

    for (start, end; start<mid; start++, end--) {
        tmp = s[start];
        s[start] = s[end];
        s[end] = tmp;
    }

}
void reverseWords(char *s)
{
    if (s == NULL) {
        return;
    }
    printf("s = %s\n", s);
    int length = strlen(s);
    int len = length/2;
    int start = 0, end = 0;
    int i = 0, j = 0;
    char *p, *q;
    char tmp;

    for (start = 0, end = length-1; start < len; start++, end--) {
        tmp = s[start];
        s[start] = s[end];
        s[end] = tmp;
    }

    printf("now s = %s\n", s);
    start = end = 0;
    while (s[end] != '\0') {
        if (s[end] != ' ') {
            start = end;
            while (s[end] != ' ' && s[end] != '\0') {
                end++;
            }
            reverseWord(s, start, end-1);
        }
        end++;
    }
    printf("after reverse, s = %s\n", s);
    
    /*shorten s*/
    start = end = 0;

}

int main()
{
    char s[] = "the       skype is blue";
    reverseWords(s);

//    printf("s = %s\n", s);

}
