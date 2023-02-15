def judge(a, b):
    if a == '(' and b == ')':
        return 1
    if a == '[' and b == ']':
        return 1
    return 0


N = 110
INF = int(1e18)
s = " " + input()
n = len(s) - 1

dp = [[0] * N for _ in range(N)]

for len in range(2, n + 1):
    i, j = 1, len
    while j <= n:
        if judge(s[i], s[j]):
            dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 2)
        for k in range(i, j + 1):
            dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j])
        i += 1
        j += 1

print(n - dp[1][n])