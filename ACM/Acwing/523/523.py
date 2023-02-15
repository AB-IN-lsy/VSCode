'''
Author: NEFU AB-IN
Date: 2022-04-07 11:35:24
FilePath: \ACM\Acwing\523.py
LastEditTime: 2022-04-07 11:35:24
'''
N = 2010
B = 1
dp = [[0] * N for _ in range(N)]
st = [[0] * N for _ in range(N)]
s = [[0] * N for _ in range(N)]

t, k = map(int, input().split())

for i in range(N - B):
    for j in range(i + 1):
        if i == j: dp[i + B][j + B] = 1
        else:
            dp[i + B][j + B] = dp[i - 1 + B][j - 1 + B] + dp[i - 1 + B][j + B]
        st[i + B][j + B] = dp[i + B][j + B] % k == 0

for i in range(1, N):
    for j in range(1, N):
        s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + st[i][j]

for _ in range(t):
    n, m = map(int, input().split())
    n += B
    m += B
    print(s[n][m] - s[B - 1][m] - s[n][B - 1] + s[B - 1][B - 1])
