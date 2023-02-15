'''
Author: NEFU AB-IN
Date: 2022-03-05 16:18:39
FilePath: \Acwing\2.py
LastEditTime: 2022-07-23 14:09:05
'''

N = 1010
w, v, dp = [0] * N, [0] * N, [0] * N

n, m = map(int, input().split())
for i in range(n):
    v[i], w[i] = map(int, input().split())

for i in range(n):
    for j in range(m, v[i] - 1, -1):
        dp[j] = max(dp[j], dp[j - v[i]] + w[i])

print(dp[m])