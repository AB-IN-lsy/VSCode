'''
Author: NEFU AB-IN
Date: 2022-03-13 21:36:50
FilePath: \ACM\Acwing\285.py
LastEditTime: 2022-03-14 08:09:37
'''
import sys

sys.setrecursionlimit(int(2e9))

N = 6100
dp = [[0] * 2 for _ in range(N)]
w = [0] * N
g = [[] for _ in range(N)]
deg = [0] * N


def dfs(u):
    for v in g[u]:
        dfs(v)
        dp[u][0] += max(dp[v][0], dp[v][1])
        dp[u][1] += dp[v][0]


n = int(input())
for i in range(1, n + 1):
    w[i] = int(input())
    dp[i][1] = w[i]
for i in range(n - 1):
    v, u = map(int, input().split())
    g[u].append(v)
    deg[v] += 1
for i in range(1, n + 1):
    if deg[i] == 0:
        dfs(i)
        print(max(dp[i][0], dp[i][1]))
        break
