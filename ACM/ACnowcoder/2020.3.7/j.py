'''
Author: NEFU AB-IN
Date: 2022-03-07 22:55:35
FilePath: \ACM\ACnowcoder\2020.3.7\j.py
LastEditTime: 2022-03-07 23:01:21
'''
N = int(1e4 + 100)
v, w, dp, cnt = [0] * N, [0] * N, [0] * N, [0] * N
num = [[] for _ in range(N)]

n, m = map(int, input().split())
for i in range(1, n + 1):
    v[i], w[i] = map(int, input().split())
for i in range(1, n + 1):
    for j in range(m, v[i] - 1, -1):
        if dp[j] < dp[j - v[i]] + w[i]:
            dp[j] = dp[j - v[i]] + w[i]
            cnt[j] = cnt[j - v[i]] + 1
            num[j] = num[j - v[i]] + [i]
print(dp[m], cnt[m], num[m])