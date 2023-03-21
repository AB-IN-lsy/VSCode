'''
Author: NEFU AB-IN
Date: 2023-03-19 20:48:23
FilePath: \Acwing\3628\3628.py
LastEditTime: 2023-03-19 20:52:40
'''
read = lambda: map(int, input().split())
from collections import Counter, deque
from heapq import heappop, heappush
from itertools import permutations

N = int(1e3 + 10)
INF = int(2e9)


def p(a, b, mod):
    res = 1
    while b:
        if b & 1:
            res = res * a % mod
        a = a * a % mod
        b = b // 2
    return res


x, n = read()
print(p(x, n, 233333))