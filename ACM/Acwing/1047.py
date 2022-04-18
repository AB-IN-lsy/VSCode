'''
Author: NEFU AB-IN
Date: 2022-04-02 20:46:56
FilePath: \ACM\Acwing\1047.py
LastEditTime: 2022-04-02 20:46:57
'''
N = 110
INF = int(1e18)
f = [[-INF] * N for _ in range(N)]
n, k = map(int, input().split())
w = [0]
for i in range(n):
    w.append(int(input()))

f[0][0] = 0
for i in range(1, n + 1):
    for j in range(k):
        f[i][j] = max(f[i - 1][j], f[i - 1][(j - w[i]) % k] + w[i])

print(f[n][0])