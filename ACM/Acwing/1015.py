'''
Author: NEFU AB-IN
Date: 2022-03-23 19:20:42
FilePath: \ACM\Acwing\1015.py
LastEditTime: 2022-03-23 19:20:43
'''
N = 110
dp = [[0] * N for _ in range(N)]

for _ in range(int(input())):
    r, c = map(int, input().split())
    for i in range(1, r + 1):
        dp[i][1:] = list(map(int, input().split()))

    for i in range(1, r + 1):
        for j in range(1, c + 1):
            dp[i][j] = max(dp[i][j] + dp[i][j - 1], dp[i][j] + dp[i - 1][j])
    print(dp[r][c])