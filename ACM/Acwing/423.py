'''
Author: NEFU AB-IN
Date: 2022-03-05 16:31:46
FilePath: \ACM\Acwing\423.py
LastEditTime: 2022-03-05 16:31:46
'''
N = 1010

t, m, dp = [0] * N, [0] * N, [0] * N
T, M = map(int, input().split())

for i in range(M):
    t[i], m[i] = map(int, input().split())

for i in range(M):
    for j in range(T, t[i] - 1, -1):
        dp[j] = max(dp[j], dp[j - t[i]] + m[i])

print(dp[T])