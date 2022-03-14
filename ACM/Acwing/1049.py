'''
Author: NEFU AB-IN
Date: 2022-03-13 21:23:33
FilePath: \ACM\Acwing\1049.py
LastEditTime: 2022-03-13 21:23:34
'''
for _ in range(int(input())):
    N = int(1e5 + 10)
    dp = [0] * N
    w = [0] * N
    n = int(input())
    w[1:] = list(map(int, input().split()))

    dp[1] = w[1]
    for i in range(2, n + 1):
        dp[i] = max(dp[i - 1], dp[i - 2] + w[i])
    print(dp[n])