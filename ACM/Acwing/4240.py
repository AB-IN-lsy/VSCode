'''
Author: NEFU AB-IN
Date: 2022-04-16 10:21:21
FilePath: \ACM\Acwing\4240.py
LastEditTime: 2022-04-16 10:22:45
'''
from collections import deque

N = 220
INF = int(1e9)
g = [[] for _ in range(N)]
dist, st = [INF] * N, [0] * N


def spfa(u):
    st[u] = 1
    q = deque()
    q.appendleft(u)
    dist[u] = 0
    while q:
        u = q.pop()
        st[u] = 0
        for v, w in g[u]:
            if dist[v] > max(dist[u], w):
                dist[v] = max(dist[u], w)
                if st[v] == 0:
                    st[v] = 1
                    q.appendleft(v)
    return dist[2]


def cale(x1, y1, x2, y2):
    return pow((x1 - x2)**2 + (y1 - y2)**2, 0.5)


while True:
    n = int(input())
    if n == 0:
        break
    lst = [0]
    dist, st = [INF] * N, [0] * N
    for i in range(n):
        x, y = map(int, input().split())
        lst.append([x, y])
    for i in range(1, n + 1):
        for j in range(i + 1, n + 1):
            x1, y1 = lst[i]
            x2, y2 = lst[j]
            w = cale(x1, y1, x2, y2)
            g[i].append([j, w])
            g[j].append([i, w])
    print(f"{spfa(1):.3f}")
    tmp = input()
