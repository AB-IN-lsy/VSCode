'''
Author: NEFU AB-IN
Date: 2023-03-23 21:42:54
FilePath: \Acwing\1051\1051.py
LastEditTime: 2023-03-23 21:54:54
'''
read = lambda: map(int, input().split())
from collections import Counter, deque
from heapq import heappop, heappush
from itertools import permutations

N = int(5e4 + 10)
INF = int(2e9)

dp, g, h, w = [0] * N, [0] * N, [0] * N, [0] * N

for _ in range(int(input())):
    n = int(input())
    w[1:] = list(read())

    # s = -INF
    dp[0] = g[0] = -INF  # 这里设成负无穷 是因为每一段都不能是空的，无解就设成-INF
    for i in range(1, n + 1):
        dp[i] = w[i] + max(0, dp[i - 1])
        # s = max(0, s) + w[i]
        g[i] = max(dp[i], g[i - 1])
        # g[i] = max(s, g[i - 1])

    # s = -INF
    dp[n + 1] = h[n + 1] = -INF
    for i in range(n, 0, -1):
        dp[i] = w[i] + max(0, dp[i + 1])
        # s = max(0, s) + w[i]
        h[i] = max(dp[i], h[i + 1])
        # h[i] = max(s, h[i + 1])

    res = -INF
    for i in range(1, n + 1):
        res = max(res, g[i] + h[i + 1])
    print(res)