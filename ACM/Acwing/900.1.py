'''
Author: NEFU AB-IN
Date: 2022-03-07 22:28:25
FilePath: \ACM\Acwing\900.1.py
LastEditTime: 2022-03-07 22:31:58
'''
N = 1100
MOD = int(1e9 + 7)
dp = [[0] * N for _ in range(N)]

n = int(input())
dp[0][0] = 1

for i in range(1, n + 1):
    for j in range(1, n + 1):
        dp[i][j] = (dp[i - 1][j - 1] + dp[i - j][j]) % MOD

res = 0
for i in range(1, n + 1):
    res = (res + dp[n][i]) % MOD
print(res)