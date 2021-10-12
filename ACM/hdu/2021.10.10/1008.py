'''
Author: NEFU AB-IN
Date: 2021-10-10 15:05:01
FilePath: \ACM\Hdu\2021.10.10\1008.py
LastEditTime: 2021-10-10 15:21:57
'''
import itertools as it


def f(n, k):
    l = []
    for i in range(1, n + 1):
        l.append(i)
    lst = list(it.permutations(l))
    ll = []
    for i in lst:
        ll += i
    ####
    l = []
    for i in range(1, k + 1):
        l.append(i)
    lst = list(it.permutations(l))
    ans = 0
    for i in range(len(ll) - k + 1):
        if tuple(ll[i:i + k]) in lst:
            ans += 1
    print(ans, end=" ")


for n in range(1, 10):
    for k in range(1, n + 1):
        f(n, k)
    print()
