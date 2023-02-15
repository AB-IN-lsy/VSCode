'''
Author: NEFU AB-IN
Date: 2022-03-03 18:52:55
FilePath: \ACM\Acwing\858.py
LastEditTime: 2022-03-03 19:13:17
'''
N = 550
INF = int(2e9)
g = [[INF] * N for _ in range(N)]
st, dist = [0] * N, [INF] * N


def prim():
    res = 0
    for i in range(n):
        t = -1
        for j in range(1, n + 1):
            if (st[j] == 0 and (t == -1 or dist[t] > dist[j])):
                t = j
        if i and dist[t] == INF:
            return INF
        if i:
            res += dist[t]
        for j in range(1, n + 1):
            dist[j] = min(dist[j], g[j][t])
        st[t] = 1
    return res


n, m = map(int, input().split())
for i in range(m):
    x, y, z = map(int, input().split())
    g[x][y] = g[y][x] = min(g[x][y], z)
res = prim()
if res == INF:
    print("impossible")
else:
    print(res)