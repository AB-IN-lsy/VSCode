'''
Author: NEFU AB-IN
Date: 2022-03-11 15:59:10
FilePath: \ACM\Acwing\223.py
LastEditTime: 2022-03-11 21:30:05
'''

N = 20
m, a = [0] * N, [0] * N


def exgcd(a, b):
    global x, y
    if b == 0:
        x, y = 1, 0
        return a
    d = exgcd(b, a % b)
    x, y = y, x
    y -= (a // b) * x
    return d


n = int(input())

p = 1
for i in range(n):
    m[i], a[i] = map(int, input().split())
    p *= m[i]

x, y, ans = 0, 0, 0
for i in range(n):
    M = p // m[i]
    exgcd(M, m[i])
    ans += a[i] * M * x

print(ans)
