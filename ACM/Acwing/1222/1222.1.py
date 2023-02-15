'''
Author: NEFU AB-IN
Date: 2022-04-03 10:55:42
FilePath: \ACM\Acwing\1222.1.py
LastEditTime: 2022-04-03 12:33:05
'''
N = int(1e3 + 10)
dp = [[0] * N for _ in range(N)]

s = " " + input()
n = len(s) - 1

for len in range(1, n + 1):
    i, j = 1, len
    while j <= n:
        if len == 1:
            dp[i][j] = 1
        else:
            dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
            if s[i] == s[j]:
                dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 2)
        i += 1
        j += 1

print(n - dp[1][n])