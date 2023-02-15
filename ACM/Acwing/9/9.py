'''
Author: NEFU AB-IN
Date: 2022-03-06 15:42:55
FilePath: \ACM\Acwing\9.py
LastEditTime: 2022-03-06 15:42:56
'''
N = 110

v, w = [[0] * N for _ in range(N)], [[0] * N for _ in range(N)]
s, dp = [0] * N, [0] * N
n, m = map(int, input().split())

for i in range(1, n + 1):
    s[i] = int(input())
    for j in range(1, s[i] + 1):
        v[i][j], w[i][j] = map(int, input().split())

for i in range(1, n + 1):
    for j in range(m, -1, -1):
        for k in range(1, s[i] + 1):
            if j - v[i][k] >= 0:
                dp[j] = max(dp[j], dp[j - v[i][k]] + w[i][k])

print(dp[m])