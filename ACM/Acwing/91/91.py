'''
Author: NEFU AB-IN
Date: 2022-03-13 19:45:52
FilePath: \ACM\Acwing\91.py
LastEditTime: 2022-03-13 20:39:48
'''
N = 23
M = 838860
INF = int(2e9)
w = [[0] * N for _ in range(N)]
dp = [[INF] * N for _ in range(M)]

n = int(input())
for i in range(n):
    w[i] = list(map(int, input().split()))

dp[1][0] = 0
for i in range(1 << n):
    for j in range(n):
        if i >> j & 1:
            pre = i - (1 << j)
            for k in range(n):
                if (pre >> k & 1):  #i 除去j这个点后要包含k，才能保证k转移到j
                    dp[i][j] = min(dp[i][j], dp[pre][k] + w[k][j])

print(dp[(1 << n) - 1][n - 1])

s = '1'
s.isalpha()