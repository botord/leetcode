#!/usr/bin/env python
# coding=utf-8

#A = [1,2,3,4,5]
#B = [3,4,5,6,7]
A = [1,2]
B = [3,4]

def findMedianSortedArrays(A, B):
    """
    A: an integer array
    B: an integer array
    return the median value of A and B.
    """
    n = len(A) + len(B)
    if n % 2 == 1:
        return findKth(A, B, n/2 + 1)
    else:
        small = findKth(A, B, n/2)
        big = findKth(A, B, n/2 + 1)
        return (small+big)/2.0

def findKth(A, B, k):
        if len(B) < len(A):
            return findKth(B, A, k)
        if len(A) == 0:
            print "B[%d] = %d" % (k-1 , B[k-1])
            return B[k-1]
        if k == 1:
            print "min(A[0],B[0]) = %d" % (min(A[0], B[0]))
            return min(A[0], B[0])

        mid_a = min(k/2, len(A))
        mid_b = k - mid_a

        if A[mid_a-1] <= B[mid_b-1]:
            print "A[%d] = %d B[%d] = %d" % (mid_a-1, A[mid_a-1], mid_b-1, B[mid_b-1])
            return findKth(A[mid_a:], B, mid_b)
        elif A[mid_a-1] > B[mid_b-1]:
            print "A[%d] = %d B[%d] = %d" % (mid_a-1, A[mid_a-1], mid_b-1, B[mid_b-1])
            return findKth(A, B[mid_b:], mid_a)
        else:
            print "A[%d] = %d" % (mid_a-1 , A[mid_a-1])
            return A[mid_a - 1]

if __name__ == '__main__':
    print A, B
    res = findMedianSortedArrays(A,B)
    print res
    
