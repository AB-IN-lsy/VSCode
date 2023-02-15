'''
Author: NEFU AB-IN
Date: 2022-03-06 17:23:37
FilePath: \ACM\Acwing\895.py
LastEditTime: 2022-03-06 17:27:52
'''
N = 1100

dp, a = [0] * N, [0] * N
n = int(input())

a[1:] = map(int, input().split())

for i in range(1, n + 1):
    dp[i] = 1
    for j in range(1, i + 1):
        if a[i] > a[j]:
            dp[i] = max(dp[i], dp[j] + 1)

res = 0
for i in range(1, n + 1):
    res = max(res, dp[i])
print(res)