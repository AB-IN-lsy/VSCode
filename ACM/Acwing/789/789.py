'''
Author: NEFU AB-IN
Date: 2022-02-19 12:03:04
FilePath: \ACM\Acwing\789.py
LastEditTime: 2022-02-19 21:06:19
'''

from collections import Counter

a = []


def findl(x):
    l = 0
    r = len(a) - 1
    while l < r:
        mid = l + r >> 1
        if a[mid] >= x:
            r = mid
        else:
            l = mid + 1
    return r


def findr(x):
    l = 0
    r = len(a) - 1
    while l < r:
        mid = l + r + 1 >> 1
        if a[mid] <= x:
            l = mid
        else:
            r = mid - 1
    return r


if __name__ == "__main__":
    n, q = map(int, input().split())
    a = list(map(int, input().split()))
    for i in range(q):
        x = int(input())
        L = findl(x)
        R = findr(x)
        if a[L] != x or a[R] != x:
            print(-1, -1)
        else:
            print(L, R)