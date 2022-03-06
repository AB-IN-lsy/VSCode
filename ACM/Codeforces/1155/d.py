'''
Author: NEFU AB-IN
Date: 2022-03-05 18:58:47
FilePath: \ACM\Codeforces\1155\d.py
LastEditTime: 2022-03-05 22:56:34
'''
N = int(3e5 + 10000)
dp = [[0] * 3 for _ in range(N)]
a = [0] * N
INF = int(2e9)

n, x = map(int, input().split())
a[1:] = list(map(int, input().split()))
maxn = 0

for i in range(1, n + 1):
    dp[i][0] = max(0, dp[i - 1][0] + a[i])
    dp[i][1] = max(dp[i][0], dp[i - 1][1] + a[i] * x)
    dp[i][2] = max(dp[i][1], dp[i - 1][2] + a[i])
    maxn = max(maxn, dp[i][2])

print(maxn)