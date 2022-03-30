'''
Author: NEFU AB-IN
Date: 2022-03-30 10:47:10
FilePath: \ACM\Acwing\1055.1.py
LastEditTime: 2022-03-30 11:19:52
'''
N = int(1e5 + 10)
dp = [[0] * 2 for _ in range(N)]

n = int(input())
a = list(map(int, input().split()))
a = [0, *a]

dp[0][1] = -int(1e9)
for i in range(1, n + 1):
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + a[i])
    dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - a[i])

print(dp[n][0])