#!/usr/bin/env python
# coding=utf-8

num = [3,2,4]
target = 6

def twoSum(num, target):
        hash = {} 
        for i in xrange(len(num)):
            if (target-num[i]) in hash:
                print "target = ", target
                print "hash[%d] = %d" % (target-num[i], hash[target-num[i]])
                print "hash[%d] = %d" % (num[i], i)
                return (hash[target-num[i]], i)
            hash[num[i]] = i

        return [-1, -1]

if __name__ == '__main__':
    twoSum(num,target)
