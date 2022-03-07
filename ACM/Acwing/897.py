'''
Author: NEFU AB-IN
Date: 2022-03-07 16:21:35
FilePath: \ACM\Acwing\897.py
LastEditTime: 2022-03-07 18:16:17
'''
N, M = 1100, 1100

dp = [[0] * M for _ in range(N)]

n, m = map(int, input().split())

a = " " + input()
b = " " + input()

for i in range(1, n + 1):
    for j in range(1, m + 1):
        dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]))
        if a[i] == b[j]:
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1)
print(dp[n][m])