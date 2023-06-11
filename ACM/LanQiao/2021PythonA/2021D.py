'''
Author: NEFU AB-IN
Date: 2022-03-15 21:18:12
FilePath: \ACM\LanQiao\2021D.py
LastEditTime: 2022-03-15 21:37:35
'''
from collections import deque

N = 2030
INF = int(2e9)
st = [0] * N
dist = [INF] * N
g = [[] for _ in range(N)]


def gcd(a, b):
    return gcd(b, a % b) if b else a


def spfa():
    q = deque()
    q.appendleft(1)
    st[1] = 1
    dist[1] = 0
    while q:
        u = q.pop()
        st[u] = 0

        for v, w in g[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                if st[v] == 0:
                    q.appendleft(v)
                    st[v] = 1
    if dist[2021] > INF / 2:
        return -1
    return dist[2021]


for i in range(1, 2022):
    for j in range(i + 1, 2022):
        if abs(i - j) <= 21:
            w = i // gcd(i, j) * j
            g[i].append([j, w])
            g[j].append([i, w])
        else:
            break

print(spfa())
