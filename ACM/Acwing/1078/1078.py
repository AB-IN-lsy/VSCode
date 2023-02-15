'''
Author: NEFU AB-IN
Date: 2022-04-05 10:57:05
FilePath: \ACM\Acwing\1078.py
LastEditTime: 2022-04-05 10:58:50
'''
import sys

sys.setrecursionlimit(int(2e9))

N = int(2e5 + 10)
g = [[] for _ in range(N)]
dist1, dist2, st = [0] * N, [0] * N, [0] * N
ans = 0


def dfs(fa, u):
    global ans
    for v in g[u]:
        if v == fa:
            continue
        dfs(u, v)
        dis = dist1[v] + 1
        if dis > dist1[u]:
            dist2[u] = dist1[u]
            dist1[u] = dis
        elif dis > dist2[u]:
            dist2[u] = dis
    ans = max(ans, dist1[u] + dist2[u])


def dfs1(fa, u):
    st[u] = 1
    for v in g[u]:
        if v == fa:
            continue
        if dist1[u] == dist1[v] + 1:
            dfs1(u, v)


def dfs2(fa, u):
    st[u] = 1
    for v in g[u]:
        if v == fa:
            continue
        if dist2[u] == dist1[v] + 1:
            dfs1(u, v)


n = int(input())
for i in range(n - 1):
    u, v = map(int, input().split())
    g[u].append(v)
    g[v].append(u)

dfs(-1, 0)

for i in range(n):
    if ans == dist1[i] + dist2[i]:
        dfs1(-1, i)
        dfs2(-1, i)

for i in range(n):
    if st[i]:
        print(i)