'''
Author: NEFU AB-IN
Date: 2022-04-06 22:47:25
FilePath: \ACM\Acwing\1171.py
LastEditTime: 2022-04-06 23:02:31
'''
import sys

sys.setrecursionlimit(int(2e9))


class Query():
    def __init__(self, index, v):
        self.index = index
        self.v = v


N = int(1e4 + 10)
g = [[] for _ in range(N)]
p = [i for i in range(N)]
st, dist = [0] * N, [0] * N
res = [[] for _ in range(N)]

ans = [0] * N * 2


def find(x):
    if x != p[x]:
        p[x] = find(p[x])
    return p[x]


def dfs(fa, u):
    for v, w in g[u]:
        if fa == v:
            continue
        dist[v] = dist[u] + w
        dfs(u, v)


def tarjan(u):
    st[u] = 1
    for v, w in g[u]:
        if not st[v]:
            tarjan(v)
            p[v] = u

    for q in res[u]:
        if st[q.v] == 2:
            lca = find(q.v)
            ans[q.index] = dist[u] + dist[q.v] - 2 * dist[lca]

    st[u] = 2


n, m = map(int, input().split())
for i in range(n - 1):
    x, y, k = map(int, input().split())
    g[x].append([y, k])
    g[y].append([x, k])
for i in range(m):
    x, y = map(int, input().split())
    if x != y:
        res[x].append(Query(i, y))
        res[y].append(Query(i, x))

dfs(-1, 1)
tarjan(1)

for i in range(m):
    print(ans[i])
