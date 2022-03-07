'''
Author: NEFU AB-IN
Date: 2022-03-07 20:22:14
FilePath: \ACM\Acwing\282.py
LastEditTime: 2022-03-07 20:30:56
'''
N = 310
INF = int(2e9)
dp = [[0] * N for _ in range(N)]
s = [0] * N

n = int(input())
s[1:] = map(int, input().split())
for i in range(1, n + 1):
    s[i] += s[i - 1]

for len in range(2, n + 1):  #先枚举区间长度
    for i in range(1, n - len + 2):  #枚举左端点, 边界为 i + len - 1 <= n
        j = i + len - 1
        dp[i][j] = INF
        for k in range(i, j + 1):
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + s[j] - s[i - 1])

print(dp[1][n])