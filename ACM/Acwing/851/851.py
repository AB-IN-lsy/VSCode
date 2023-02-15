'''
Author: NEFU AB-IN
Date: 2022-03-03 12:15:39
FilePath: \ACM\Acwing\851.py
LastEditTime: 2022-03-03 12:34:28
'''

from collections import deque

N = int(1e5 + 10)
INF = int(2e9)
st, dist = [0] * N, [INF] * N
g = [[] for _ in range(N)]
q = deque()


def spfa(s):
    dist[s] = 0
    q.appendleft(s)
    st[s] = 1
    while q:
        u = q.pop()
        st[u] = 0
        for v, w in g[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                if st[v] == 0:
                    q.appendleft(v)
    return dist[n]


n, m = map(int, input().split())
for i in range(m):
    x, y, z = map(int, input().split())
    g[x].append([y, z])
res = spfa(1)
if res == INF:
    print("impossible")
else:
    print(res)