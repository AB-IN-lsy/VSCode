'''
Author: NEFU AB-IN
Date: 2022-04-07 18:53:55
FilePath: \ACM\Acwing\2067.py
LastEditTime: 2022-04-07 18:53:56
'''
N = 50
dp = [[0] * N for _ in range(N)]
n, m = map(int, input().split())

dp[1][1] = 1
for i in range(1, n + 1):
    for j in range(1, m + 1):
        if i % 2 == 0 and j % 2 == 0:
            continue
        dp[i][j] += (dp[i][j - 1] + dp[i - 1][j])

print(dp[n][m])