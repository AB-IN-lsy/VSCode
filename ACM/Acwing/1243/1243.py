'''
Author: NEFU AB-IN
Date: 2022-04-02 14:07:41
FilePath: \ACM\Acwing\1243.py
LastEditTime: 2022-04-02 14:14:11
'''
N = 110
INF = int(1e18)
lst = []
a = [0] * N
f = [INF] * (1 << 21)

n, m, k = map(int, input().split())
for i in range(n):
    b = list(map(int, input().split()))
    for j in b:
        a[i] |= 1 << (j - 1)

f[0] = 0
for i in range(n):
    for j in range(1 << m):
        f[j] = min(f[j], f[j & (~a[i])] + 1)

if f[(1 << m) - 1] > n:
    print(-1)
else:
    print(f[(1 << m) - 1])