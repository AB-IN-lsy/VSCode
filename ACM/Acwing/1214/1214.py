'''
Author: NEFU AB-IN
Date: 2022-03-24 11:41:45
FilePath: \ACM\Acwing\1214.py
LastEditTime: 2022-03-24 11:41:46
'''
MOD = 100000007
N = 1010
dp = [[0] * N for _ in range(N)]

n, s, a, b = map(int, input().split())

dp[0][0] = 1

for i in range(1, n + 1):
    for j in range(0, n):
        dp[i][j] = (dp[i][j] + dp[i - 1][(j - a * i) % n]) % MOD
        dp[i][j] = (dp[i][j] + dp[i - 1][(j + b * i) % n]) % MOD

print(dp[n - 1][s % n])