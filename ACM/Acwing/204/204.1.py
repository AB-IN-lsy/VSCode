'''
Author: NEFU AB-IN
Date: 2022-04-12 11:51:51
FilePath: \Acwing\204\204.1.py
LastEditTime: 2023-02-15 17:39:21
'''


def gcd(a, b):
    return gcd(b, a % b) if b else a


def exgcd(a, b):
    global x, y
    if b == 0:
        x, y = 1, 0
        return a
    d = exgcd(b, a % b)
    x, y = y, x
    y -= (a // b) * x
    return d


d = []
n = int(input())

for _ in range(n):
    m, a = map(int, input().split())
    d.append([m, a])

i = 0
while i < n:
    m, a = d[i]
    if i == 0:
        lcm, ans = m, a
    x, y = 0, 0
    dd = exgcd(lcm, m)
    if (a - ans) % dd:
        print(-1)
        exit(0)
    if ans % m == a:
        lcm = lcm // gcd(lcm, m) * m
        i += 1
    else:
        ans += (x * lcm + y * m) % m

print(ans)