'''
Author: NEFU AB-IN
Date: 2022-03-06 11:58:08
FilePath: \ACM\Acwing\4.py
LastEditTime: 2022-03-06 12:06:39
'''
n, m = map(int, input().split())

N = 110
v, w, s = [0] * N, [0] * N, [0] * N
dp = [[0] * N for _ in range(N)]

for i in range(1, n + 1):
    v[i], w[i], s[i] = map(int, input().split())

for i in range(1, n + 1):
    for j in range(0, m + 1):
        k = 0
        while k <= s[i] and k * v[i] <= j:
            dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i] * k] + w[i] * k)
            k += 1

print(dp[n][m])