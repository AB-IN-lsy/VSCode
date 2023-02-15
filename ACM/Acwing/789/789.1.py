'''
Author: NEFU AB-IN
Date: 2022-02-20 14:56:18
FilePath: \ACM\Acwing\789.1.py
LastEditTime: 2022-02-20 14:59:33
'''
from bisect import bisect_left, bisect_right

n, q = map(int, input().split())
a = list(map(int, input().split()))

for i in range(q):
    x = int(input())
    L = bisect_left(a, x)
    R = bisect_right(a, x) - 1
    if L >= n or R >= n or a[L] != x or a[R] != x:
        print(-1, -1)
    else:
        print(L, R)