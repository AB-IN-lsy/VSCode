'''
Author: NEFU AB-IN
Date: 2022-04-04 20:08:15
FilePath: \ACM\Acwing\1226.py
LastEditTime: 2022-04-04 20:09:25
'''


def gcd(a, b):
    return gcd(b, a % b) if b else a


N = int(1e4 + 10)
n = int(input())
a, f = [], [0] * N

d = 0
for i in range(n):
    x = int(input())
    a.append(x)
    d = gcd(d, x)
if d > 1:
    print("INF")
    exit(0)

f[0] = 1
for i in range(n):
    for j in range(a[i], N):
        f[j] = f[j] | f[j - a[i]]

ans = 0
for i in range(N):
    if not f[j]:
        ans += 1
print(ans)
