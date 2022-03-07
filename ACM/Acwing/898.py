'''
Author: NEFU AB-IN
Date: 2022-03-06 16:40:50
FilePath: \ACM\Acwing\898.py
LastEditTime: 2022-03-06 16:44:20
'''
N = 510

dp = [[0] * N for _ in range(N)]

n = int(input())
for i in range(1, n + 1):
    dp[i][1:] = map(int, input().split())

for i in range(n - 1, 0, -1):
    for j in range(1, i + 1):
        dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1])

print(dp[1][1])
