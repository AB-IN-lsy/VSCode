'''
Author: NEFU AB-IN
Date: 2022-03-03 15:45:54
FilePath: \ACM\Acwing\854.py
LastEditTime: 2022-03-03 16:01:18
'''
N = int(250)
INF = int(2e9)
g = [[0] * N for _ in range(N)]
dist = [[INF] * N for _ in range(N)]


def floyd():
    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])


n, m, q = map(int, input().split())
for i in range(1, n + 1):
    for j in range(1, n + 1):
        if i == j:
            dist[i][j] = 0

for i in range(m):
    x, y, z = map(int, input().split())
    dist[x][y] = min(dist[x][y], z)

floyd()
for i in range(q):
    x, y = map(int, input().split())
    if dist[x][y] > INF // 2:
        print("impossible")
    else:
        print(dist[x][y])