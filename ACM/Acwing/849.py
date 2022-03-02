'''
Author: NEFU AB-IN
Date: 2022-03-02 22:20:20
FilePath: \ACM\Acwing\849.py
LastEditTime: 2022-03-02 23:21:42
'''
import heapq

N = int(1e3 + 10)
INF = int(2e9)
st, dist = [0] * N, [INF] * N
g = [[INF] * N for _ in range(N)]


def dij(s):
    dist[s] = 0
    for i in range(n):  #循环n次
        t = -1
        for j in range(1, n + 1):
            if st[j] == 0 and (t == -1 or dist[t] > dist[j]):  #每次挑出最小的点
                t = j
        st[t] = 1  #加入最短路
        for j in range(1, n + 1):  #用t点的最短路，更新j点的最短路
            dist[j] = min(dist[j], dist[t] + g[t][j])
    if dist[n] == INF:
        return -1
    return dist[n]


n, m = map(int, input().split())
for i in range(m):
    x, y, z = map(int, input().split())
    g[x][y] = min(g[x][y], z)  #保留最短的那条边

print(dij(1))