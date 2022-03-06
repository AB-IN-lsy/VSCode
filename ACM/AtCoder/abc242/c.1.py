'''
Author: NEFU AB-IN
Date: 2022-03-06 10:44:01
FilePath: \ACM\AtCoder\abc242\c.1.py
LastEditTime: 2022-03-06 10:44:02
'''
N = int(input())

dp = [[0] * 11 for _ in range(N)]
for i in range(1, 10):
    dp[0][i] = 1

mod = 998244353
for i in range(1, N):
    for j in range(1, 10):
        dp[i][j] += dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]
        dp[i][j] %= mod

print(sum(dp[-1]) % mod)
