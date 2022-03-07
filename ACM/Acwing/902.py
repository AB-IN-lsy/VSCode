'''
Author: NEFU AB-IN
Date: 2022-03-07 17:01:46
FilePath: \ACM\Acwing\902.py
LastEditTime: 2022-03-07 17:16:51
'''
N = 1100
INF = int(2e9)
dp = [[INF] * N for _ in range(N)]

n = int(input())
a = " " + input()
m = int(input())
b = " " + input()

for i in range(m + 1):
    dp[0][i] = i  #初始化：当a的前0个字母想匹配b的前i个字母时，只能用添加操作，所以bi有多少字母，a就有几步
for i in range(n + 1):
    dp[i][0] = i  #初始化：当b的前0个字母想匹配a的前i个字母时，只能用删除操作，所以ai有多少字母，b就有几步

for i in range(1, n + 1):
    for j in range(1, m + 1):
        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1)
        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1)
        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (1 if a[i] != b[j] else 0))

print(dp[n][m])
