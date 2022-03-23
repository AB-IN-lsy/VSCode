'''
Author: NEFU AB-IN
Date: 2022-03-21 09:34:00
FilePath: \ACM\Acwing\ACC\c.py
LastEditTime: 2022-03-21 09:59:17
'''
N = 5010
INF = int(4e9)
s = [0] * N
dp = [[0] * N for _ in range(N)]

n, m, k = map(int, input().split())
a = list(map(int, input().split()))
a = [0, *a]

for i in range(1, n + 1):
    s[i] = s[i - 1] + a[i]

for i in range(m, n + 1):
    for j in range(1, k + 1):
        dp[i][j] = max(dp[i - 1][j], dp[i - m][j - 1] + s[i] - s[i - m])

print(dp[n][k])