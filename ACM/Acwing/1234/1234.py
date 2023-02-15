'''
Author: NEFU AB-IN
Date: 2022-04-06 17:46:30
FilePath: \ACM\Acwing\1234.py
LastEditTime: 2022-04-06 20:18:19
'''
INF = int(1e10)

N = int(1e3 + 10)
dp = [[0] * N for _ in range(4)]

g = [[] for _ in range(N)]

n, K = map(int, input().split())
a = list(map(int, input().split()))

for i in a:
    g[i % K].append(i)

dp[0][0] = 0
for i in range(K):
    g[i].sort(reverse=True)
    for u in range(min(3, len(g[i]))):
        x = g[i][u]
        for j in range(3, 0, -1):
            for k in range(K):
                dp[j][k] = max(dp[j][k], dp[j - 1][(k - x) % K] + x)

print(dp[3][0])
