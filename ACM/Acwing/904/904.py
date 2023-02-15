'''
Author: NEFU AB-IN
Date: 2022-04-16 16:17:22
FilePath: \ACM\Acwing\904.py
LastEditTime: 2022-04-16 16:17:23
'''
from collections import deque

N = 550
INF = int(1e9)
g = [[] for _ in range(N)]
dist, st, cnt = [INF] * N, [0] * N, [0] * N


def spfa():
    q = deque()
    for i in range(1, n + 1):
        q.appendleft(i)
        st[i] = 1
        dist[i] = 0
    while q:
        u = q.pop()
        st[u] = 0

        for v, w in g[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                if st[v] == 0:
                    st[v] = 1
                    q.appendleft(v)
                cnt[v] = cnt[u] + 1
                if cnt[v] >= n:
                    return 1
    return 0


for _ in range(int(input())):
    g = [[] for _ in range(N)]
    dist, st, cnt = [INF] * N, [0] * N, [0] * N

    n, m, w = map(int, input().split())
    for i in range(m):
        u, v, t = map(int, input().split())
        g[u].append([v, t])
        g[v].append([u, t])
    for i in range(w):
        u, v, t = map(int, input().split())
        g[u].append([v, -t])
    if spfa():
        print("YES")
    else:
        print("NO")
