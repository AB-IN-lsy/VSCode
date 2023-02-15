'''
Author: NEFU AB-IN
Date: 2022-03-06 11:29:05
FilePath: \ACM\Acwing\3.py
LastEditTime: 2022-03-06 11:35:40
'''

N = 1010
w, v, dp = [0] * N, [0] * N, [0] * N

n, m = map(int, input().split())
for i in range(n):
    v[i], w[i] = map(int, input().split())

for i in range(n):
    for j in range(v[i], m + 1):
        dp[j] = max(dp[j], dp[j - v[i]] + w[i])

print(dp[m])