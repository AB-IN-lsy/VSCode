'''
Author: NEFU AB-IN
Date: 2022-03-07 21:21:51
FilePath: \ACM\Acwing\900.py
LastEditTime: 2022-03-07 21:24:45
'''

N = 1010
MOD = int(1e9 + 7)
dp = [0] * N

n = int(input())

dp[0] = 1  #代表一个数都不选时，体积是0，方案数是1
for i in range(1, n + 1):
    for j in range(i, n + 1):
        dp[i] = (dp[i] + dp[j - i]) % MOD

print(dp[n])