'''
Author: NEFU AB-IN
Date: 2023-03-19 11:26:46
FilePath: \Acwing\3305\3305.py
LastEditTime: 2023-03-19 11:42:51
'''
read = lambda: map(int, input().split())
from collections import Counter, deque
from heapq import heappop, heappush
from itertools import permutations

N = int(2e3 + 10)
INF = int(2e9)
st, w, dist = [0] * N, [0] * N, [INF] * N
g = [[] for _ in range(N)]
q = deque()


def spfa():
    while len(q):
        u = q.pop()
        st[u] = 0
        for v, c in g[u]:
            if max(dist[u], dist[v]) + max(w[u], w[v]) < dist[c]:
                dist[c] = max(dist[u], dist[v]) + max(w[u], w[v])
                if st[c] == 0:
                    st[c] = 1
                    q.appendleft(c)


n, m, k, t = read()
w[1:] = list(read())

tmp = list(read())
for i in tmp:
    q.appendleft(i)
    st[i] = 1
    dist[i] = 0

for i in range(k):
    a, b, c = read()
    g[a].append([b, c])
    g[b].append([a, c])

spfa()

print(dist[t])
