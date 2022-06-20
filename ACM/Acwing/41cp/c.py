'''
Author: NEFU AB-IN
Date: 2022-03-05 19:31:27
FilePath: \ACM\Acwing\41周赛\c.py
LastEditTime: 2022-03-05 19:50:20
'''
import sys

sys.setrecursionlimit(int(2e9))
N = int(2e5 + 100)
g = [[] for _ in range(N)]
res = [0]
cnt = [1 for i in range(N)]
vis = [0] * N


def dfs(u):
    res.append(u)
    for v in g[u]:
        s = dfs(v)
        cnt[u] += s
    return cnt[u]


n, q = map(int, input().split())
a = list(map(int, input().split()))
for i in range(n - 1):
    g[a[i]].append(i + 2)
for i in range(1, n + 1):
    g[i].sort()

dfs(1)

for i in range(1, n + 1):
    vis[res[i]] = i
for i in range(q):
    u, k = map(int, input().split())
    if k > cnt[u]:
        print(-1)
        continue
    print(res[vis[u] + k - 1])