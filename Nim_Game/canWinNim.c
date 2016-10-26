/*************************************************************************
	> File Name: canWinNim.c
	> Author: 
	> Mail: 
	> Created Time: 2016年08月16日 星期二 09时39分56秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool canWinNim (int n) {
    if (n%4) {
        return true;
    } else {
        return false;
    }
}

int main() {
    bool res = canWinNim(1348820612);

    if (res) {
        printf("yes we can!\n");
    }
    return 0;
}
