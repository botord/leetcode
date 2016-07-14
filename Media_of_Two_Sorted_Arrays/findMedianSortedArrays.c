/*************************************************************************
	> File Name: findMedianSortedArrays.c
	> Author: 
	> Mail: 
	> Created Time: 2016年07月14日 星期四 21时25分54秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define MIN(x,y) ((x<y)?x:y)

/*find the Kth largest number in array a and b*/
double findK(int *a, int a_size, int *b, int b_size, int k)
{
    /*Make sure that length of a is always less than length of b*/
    if (a_size > b_size) {
        return findK(b, b_size, a, a_size, k);
    }
    
    /*So the problem turns out to be finding the kth smallest number*/
    if (a_size == 0) {
        /*Since a is empty, just regard b[k-1] as the kth smallest number */
        return b[k-1];
    }

    /*in case that a has a small length*/
    int i_a = MIN(a_size, k/2);
    int i_b = k - i_a;
    if (k == 1) {
        return MIN(a[0], b[0]);
    }
    if (a[i_a-1] < b[i_b-1]) {
        return findK(a+i_a, a_size-i_a, b, b_size, k-i_a);
    } else if (a[i_a-1] > b[i_b-1]) {
        return findK(a, a_size, b, b_size-i_b, k-i_b);
    } else {
        return a[i_a-1];
    }
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int mid = (nums1Size + nums2Size) / 2;
    double ret;
    
    if ((nums1Size + nums2Size) % 2)
        ret = (double)findK(nums1, nums1Size, nums2, nums2Size, mid+1);
    else
        ret = (double)(findK(nums1, nums1Size, nums2, nums2Size, mid) + 
                findK(nums1, nums1Size, nums2, nums2Size, mid)) / 2;
    return ret;
}


int main()
{
    int a[2] = {1,3};
    int b[1] = {2};

    int a_size = sizeof(a)/sizeof(a[0]);
    int b_size = sizeof(b)/sizeof(b[0]);

    double ret = findMedianSortedArrays(a, a_size, b, b_size);
    printf("ret = %lf\n", ret);
    return 0;
}
