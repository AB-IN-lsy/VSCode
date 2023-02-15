'''
Author: NEFU AB-IN
Date: 2022-04-16 15:31:37
FilePath: \ACM\Acwing\4242.py
LastEditTime: 2022-04-16 15:31:37
'''
from collections import deque

INF = int(1e9)
N = 110
dist, st, cnt = [0] * N, [0] * N, [0] * N
g = [[] for _ in range(N)]


def spfa(s, v):
    dist[s] = v
    q = deque()
    q.appendleft(s)
    st[s] = 1
    while q:
        u = q.pop()
        st[u] = 0
        for v, r, c in g[u]:
            if dist[v] < (dist[u] - c) * r:
                dist[v] = (dist[u] - c) * r
                if st[v] == 0:
                    st[v] = 1
                    q.appendleft(v)
                cnt[v] = cnt[u] + 1
                if cnt[v] >= n:
                    return 1
    return 0


n, m, s, v = input().split()
n, m, s = map(int, [n, m, s])
v = float(v)

for i in range(m):
    a, b, rab, cab, rba, cba = map(float, input().split())
    a, b = map(int, [a, b])
    g[a].append([b, rab, cab])
    g[b].append([a, rba, cba])

if spfa(s, v):
    print("YES")
else:
    print("NO")