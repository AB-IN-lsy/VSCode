'''
Author: NEFU AB-IN
Date: 2022-03-06 10:46:17
FilePath: \ACM\AtCoder\abc242\c.py
LastEditTime: 2022-03-06 10:46:18
'''
'''
Author: NEFU AB-IN
Date: 2022-03-05 20:36:01
FilePath: \ACM\AtCoder\abc242\c.py
LastEditTime: 2022-03-06 10:43:20
'''

N = int(1e6 + 10)
MOD = 998244353
dp = [[0] * 12 for _ in range(N)]

for i in range(1, 10):
    dp[1][i] = 1

n = int(input())
for i in range(2, n + 1):
    for j in range(1, 10):
        dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % MOD

print(sum(dp[n]) % MOD)