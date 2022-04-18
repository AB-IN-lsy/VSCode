'''
Author: NEFU AB-IN
Date: 2022-04-18 22:00:12
FilePath: \ACM\GPLT\2022MoNi\L3-2.PY
LastEditTime: 2022-04-18 22:02:38
'''
N = 1010
M = 525610

dp = [0] * M
n, m = map(int, input().split())
v = list(map(int, input().split()))
w = list(map(int, input().split()))

v = [0, *v]
w = [0, *w]

for i in range(1, n + 1):
    for j in range(m, v[i] - 1, -1):
        dp[j] = max(dp[j], dp[j - v[i]] + w[i])

print(dp[m])