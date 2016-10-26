/*************************************************************************
	> File Name: get_Circle_Number.c
	> Author: 
	> Mail: 
	> Created Time: 2016年10月26日 星期三 21时38分55秒
 ************************************************************************/

/*
*
* 已知有n个人和m对好友关系（存于数组r）。如果两个人是直接或间接的好友（好友的好友的好友…），
* 则认为他们属于同一个朋友圈，请写程序求出这n个人里一共有多少个朋友圈。
* 假如：n = 5 ， m = 3 ， r = {{1 , 2} , {2 , 3} , {4 , 5}}，表示有5个人，1和2是好友，
* 2和3是好友，4和5是好友，则1、2、3属于一个朋友圈，4、5属于另一个朋友圈，结果为2个朋友圈。 
*
* */
#include<stdio.h>
#include<stdlib.h>

int get_Circle_Number(int, int [][2]);

#define NUMBER_OF_RELATIONSHIP 7
#define NUMBER_OF_PEOPLE 9

void main()
{
    int n = 9;

    int relationship[NUMBER_OF_RELATIONSHIP][2] = {{1,3},{3,4},{2,5},{6,8},{8,9},{1,5},{2,6}};

    int ret = get_Circle_Number(NUMBER_OF_PEOPLE,relationship);

}

int get_father(int *father, int n) {

    if (father[n] == n) {
        return n;
    } else {
        return get_father(father, father[n]);
    }
}

void merge(int *father, int relation[2]) {

    int a = get_father(father, relation[0]);
    int b = get_father(father, relation[1]);

    if (a < b) {
        father[b] = a;
    } else {
        father[a] = b;
    }

}

int get_Circle_Number(int n, int relationship[][2]) {
    int count = 0;
    int i = 0;
    int a, b;

    int *father = (int *) malloc (sizeof(int) * (NUMBER_OF_PEOPLE + 1));

    if (!father) {
        exit(1);
    }

    printf("朋友圈关系: \n");
    for (i=0; i<NUMBER_OF_RELATIONSHIP; i++) {
        printf("(%d, %d)\t", relationship[i][0], relationship[i][1]);
    }
    puts("");

    /*initialize father[]*/
    for (i=1; i<=NUMBER_OF_PEOPLE; i++) {
        father[i] = i;
    }

    for (i=1; i<NUMBER_OF_PEOPLE+1; i++) {
        printf("father[%d] = %d\n", i, father[i]);
    }

    puts("");

    for (i=0; i<NUMBER_OF_RELATIONSHIP; i++) {
        merge(father, relationship[i]);
    }

    for (i=1; i<NUMBER_OF_PEOPLE+1; i++) {
        printf("father[%d] = %d\n", i, father[i]);
    }

    for (i=1; i<NUMBER_OF_PEOPLE; i++) {
        if (father[i] == i) {
            count++;
        }
    }
    printf("there are %d circles.\n", count);
}
