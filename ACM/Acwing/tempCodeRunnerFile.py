'''
Author: NEFU AB-IN
Date: 2022-03-07 22:28:25
FilePath: \Acwing\tempCodeRunnerFile.py
LastEditTime: 2022-08-05 21:47:54
'''
N = 1100
MOD = int(1e9 + 7)
dp = [[0] * N for _ in range(N)]  # 表示总和为i, 并且恰好为j个数的方案

n = int(input())
dp[0][0] = 1  #总和为0，恰好0个数的方案有一个

for i in range(1, n + 1):
    for j in range(1, n + 1):
        dp[i][j] = (dp[i - 1][j - 1] + dp[i - j][j]) % MOD

res = 0
for i in range(1, n + 1):
    res = (res + dp[n][i]) % MOD
print(res)