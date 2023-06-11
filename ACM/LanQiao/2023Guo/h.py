from sys import setrecursionlimit, stdin, stdout, exit
from collections import Counter, deque
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from bisect import bisect_left, bisect_right
from datetime import datetime, timedelta
from string import ascii_lowercase, ascii_uppercase
from math import log, ceil, gcd, sqrt, fabs


class sa:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __lt__(self, a):
        return self.x < a.x


N = int(1e6 + 10)
M = 20
INF = int(2e9)

read = lambda: map(int, input().split())
LTN = lambda x: ord(x.upper()) - 65
NTL = lambda x: ascii_uppercase[x]
AR = lambda x: [x] * N

# _____________________________________________________

g = [[] for _ in range(N)]
gg = [[] for _ in range(N)]

n, q = read()
color = AR(0)


def f(x, y, z):
    dist = AR(INF)
    dist[x] = 0
    st = AR(0)
    q = []
    heappush(q, [0, x])
    while q:
        t = heappop(q)
        v, dst = t[0], t[1]
        if st[x]:
            continue
        st[x] = 1
        for [v, w] in gg[x]:
            if dist[v] > dist[x] + w:
                dist[v] = dist[x] + w
                heappush(q, [v, dist[v]])

    for i in range(1, n + 1):
        if dist[i] <= y:
            color[i] = z


for i in range(1, n // 2 + 1):
    g[i].append([i * 2, 1])
    g[i].append([i * 2 + 1, 1])
    g[i * 2].append([i, 1])
    g[i * 2 + 1].append([i, 1])


def bfs(i, j):
    st = AR(0)
    st[i] = 1
    q = deque()
    q.appendleft([i, 0])
    while len(q):
        t = q.pop()
        u, dst = t[0], t[1]
        for [v, w] in g[u]:
            if st[v] == 0:
                q.appendleft([v, dst + w])
                st[v] = 1
                if v == j:
                    return dst + w


for i in range(1, n + 1):
    for j in range(i + 1, n + 1):
        if i == j:
            gg[i].append([i, 0])
            continue
        ans = bfs(i, j)
        gg[i].append([j, ans])
        gg[j].append([i, ans])

lst = AR(0)
for i in range(q):
    lst = list(read())
    if len(lst) == 4:
        x, y, z = lst[1], lst[2], lst[3]
        f(x, y, z)
    else:
        print(color[lst[1]])
'''
6 6
1 1 1 1
2 3
1 5 2 2
2 4
2 1
2 3
'''
