'''
Author: NEFU AB-IN
Date: 2022-04-03 10:00:26
FilePath: \ACM\Acwing\1222.py
LastEditTime: 2022-04-03 10:29:51
'''
N, M = 1100, 1100

dp = [[0] * M for _ in range(N)]
path = [[0] * M for _ in range(N)]

ans = ""


def LCS(i, j):
    global ans
    if i < 1 or j < 1:
        return
    if path[i][j] == 1:
        ans += a[i]
        LCS(i - 1, j - 1)
    elif path[i][j] == 2:
        LCS(i - 1, j)
    else:
        LCS(i, j - 1)


a = input()
b = " " + a[::-1]
a = " " + a
n, m = len(a) - 1, len(b) - 1

for i in range(1, n + 1):
    for j in range(1, m + 1):
        if a[i] == b[j]:
            dp[i][j] = dp[i - 1][j - 1] + 1
            path[i][j] = 1  #左上
        elif dp[i - 1][j] >= dp[i][j - 1]:
            dp[i][j] = dp[i - 1][j]
            path[i][j] = 2  #上
        else:
            dp[i][j] = dp[i][j - 1]
            path[i][j] = 3  #左

LCS(n, m)

print(ans)
print(n - dp[n][m])