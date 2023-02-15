'''
Author: NEFU AB-IN
Date: 2022-02-18 16:31:39
FilePath: \ACM\Acwing\788.1.py
LastEditTime: 2022-02-18 16:47:40
'''
from bisect import bisect_left
from copy import deepcopy

N = int(1e5 + 100)
tr = [0] * N
b = []
lowbit = lambda x: x & -x


def add(x, d):
    while x <= n:
        tr[x] += d
        x += lowbit(x)


def getsum(x):
    res = 0
    while x > 0:
        res += tr[x]
        x -= lowbit(x)
    return res


if __name__ == "__main__":
    n = int(input())
    xs = list(map(int, input().split()))
    res = 0

    a = deepcopy(xs)
    xs = list(set(xs))
    xs.sort()

    for i in range(n):
        b.append(bisect_left(xs, a[i]) + 1)  #离散化的值不能等于0
    for i in range(n):
        add(b[i], 1)
        res += (i + 1 - getsum(b[i]))  #因为i是从0开始的所以+1
    print(res)