'''
Author: NEFU AB-IN
Date: 2022-03-07 17:56:44
FilePath: \ACM\Acwing\899.py
LastEditTime: 2022-03-07 18:07:16
'''
N = 20
INF = int(2e9)
dp = [[INF] * N for _ in range(N)]

n, m = map(int, input().split())
s = [0]

for i in range(n):
    s.append(" " + input())

for k in range(m):
    b, x = input().split()
    b = " " + b
    x = int(x)
    res = 0
    for kk in range(1, n + 1):
        a = s[kk]
        for i in range(len(a)):
            dp[i][0] = i
        for i in range(len(b)):
            dp[0][i] = i
        for i in range(1, len(a)):
            for j in range(1, len(b)):
                dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1)
                dp[i][j] = min(dp[i][j],
                               dp[i - 1][j - 1] + (1 if a[i] != b[j] else 0))
        if dp[len(a) - 1][len(b) - 1] <= x:
            res += 1
    print(res)
