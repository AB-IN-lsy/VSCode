'''
Author: NEFU AB-IN
Date: 2022-04-01 19:52:10
FilePath: \ACM\Acwing\1301.py
LastEditTime: 2022-04-01 19:52:11
'''


def exgcd(a, b):
    global x, y
    if b == 0:
        x, y = 1, 0
        return a
    d = exgcd(b, a % b)
    x, y = y, x
    y -= (a // b) * x
    return d


while True:
    a, b, c, k = map(int, input().split())
    if k == 0:
        break
    x, y = 0, 0
    d = exgcd(c, 2**k)
    if (b - a) % d == 0:
        x *= (b - a) // d
        n = 2**k // d
        print(x % n)
    else:
        print("FOREVER")