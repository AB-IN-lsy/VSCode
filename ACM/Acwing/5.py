'''
Author: NEFU AB-IN
Date: 2022-03-06 14:39:14
FilePath: \ACM\Acwing\5.py
LastEditTime: 2022-03-06 14:47:29
'''
N = int(2e5 + 10)  #NlogS上取整
w, v, dp = [0] * N, [0] * N, [0] * N

n, m = map(int, input().split())

cnt = 0
for i in range(n):
    a, b, s = map(int, input().split())
    k = 1
    while s - k >= 0:
        cnt += 1
        v[cnt] = k * a
        w[cnt] = k * b
        s -= k
        k *= 2
    if s > 0:
        cnt += 1
        v[cnt] = s * a
        w[cnt] = s * b

n = cnt
for i in range(1, n + 1):
    for j in range(m, v[i] - 1, -1):
        dp[j] = max(dp[j], dp[j - v[i]] + w[i])

print(dp[m])
