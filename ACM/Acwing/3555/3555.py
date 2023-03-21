'''
Author: NEFU AB-IN
Date: 2023-03-19 17:28:09
FilePath: \Acwing\3555\3555.py
LastEditTime: 2023-03-19 17:42:30
'''
read = lambda: map(int, input().split())
from collections import Counter, deque
from heapq import heappop, heappush
from itertools import permutations

N = int(1e3 + 10)
INF = int(2e9)


def solve():
    dep, st = [0] * N, [0] * N
    fa = [[0] * 11 for _ in range(N)]
    g = [[] for _ in range(N)]
    n, m = read()
    for i in range(1, n + 1):
        ls, rs = read()
        if ls != -1: g[i].append(ls)
        if rs != -1: g[i].append(rs)

    q = deque()
    q.appendleft(1)

    dep[1] = 1
    st[1] = 1

    while (len(q)):
        u = q.pop()
        for v in g[u]:
            if st[v] == 0:
                st[v] = 1
                dep[v] = dep[u] + 1
                fa[v][0] = u
                for i in range(1, 11):
                    fa[v][i] = fa[fa[v][i - 1]][i - 1]
                q.appendleft(v)

    def lca(a, b):
        if dep[a] < dep[b]:
            a, b = b, a
        for i in range(10, -1, -1):
            if dep[fa[a][i]] >= dep[b]:
                a = fa[a][i]
        if a == b:
            return b
        for i in range(10, -1, -1):
            if fa[a][i] != fa[b][i]:
                a = fa[a][i]
                b = fa[b][i]
        return fa[a][0]

    for i in range(m):
        x, y = read()
        print(dep[x] + dep[y] - 2 * dep[lca(x, y)])


for _ in range(int(input())):
    solve()
