'''
Author: NEFU AB-IN
Date: 2022-03-14 09:29:17
FilePath: \ACM\Acwing\901.py
LastEditTime: 2022-03-14 17:06:34
'''
N = 320
f = [[-1] * N for _ in range(N)]
g = [[0] * N for _ in range(N)]


def dp(x, y):
    if f[x][y] != -1:
        return f[x][y]

    f[x][y] = 1

    for i in range(4):
        a = x + dx[i]
        b = y + dy[i]
        if a >= 1 and a <= r and b >= 1 and b <= c and g[x][y] > g[a][b]:
            f[x][y] = max(f[x][y], dp(a, b) + 1)
    return f[x][y]


r, c = map(int, input().split())

for i in range(1, r + 1):
    g[i][1:] = list(map(int, input().split()))

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
res = 1

for i in range(1, r + 1):
    for j in range(1, c + 1):
        res = max(res, dp(i, j))

print(res)
