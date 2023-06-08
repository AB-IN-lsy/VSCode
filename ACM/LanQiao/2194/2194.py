'''
Author: NEFU AB-IN
Date: 2023-05-24 15:52:19
FilePath: \LanQiao\2194\2194.py
LastEditTime: 2023-05-24 16:09:41
'''
# import
from sys import setrecursionlimit, stdin, stdout, exit
from collections import Counter, deque
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from bisect import bisect_left, bisect_right
from datetime import datetime, timedelta
from string import ascii_lowercase, ascii_uppercase
from math import log, gcd, sqrt, fabs, ceil, floor


class sa:
    def __init__(self, w, v):
        self.v = v
        self.w = w

    def __lt__(self, a):
        return self.w < a.w


# Final
N = int(1e5 + 10)
M = 20
INF = int(2e9)

# Define
setrecursionlimit(INF)
input = lambda: stdin.readline().rstrip("\r\n")  # Remove when Mutiple data
read = lambda: map(int, input().split())
LTN = lambda x: ord(x.upper()) - 65  # A -> 0
NTL = lambda x: ascii_uppercase[x]  # 0 -> A

# —————————————————————Division line ——————————————————————
W = [0] * N
dist = [INF] * N
st = [0] * N
g = [[] for _ in range(N)]


def dij():
    dist[1] = 0
    q = []
    heappush(q, sa(0, 1))
    while len(q):
        a = heappop(q)
        u, w = a.v, a.w
        if st[u]:
            continue
        st[u] = 1
        for [v, w] in g[u]:
            cost = dist[u] + w + (W[v] if v != n else 0)
            if cost <= dist[v]:
                dist[v] = cost
                heappush(q, sa(cost, v))
    return dist[n]


n, m = read()
W[1:] = read()

for i in range(m):
    u, v, w = read()
    g[u].append([v, w])
    g[v].append([u, w])

print(dij())