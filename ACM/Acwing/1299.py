'''
Author: NEFU AB-IN
Date: 2022-04-01 16:43:26
FilePath: \ACM\Acwing\1299.py
LastEditTime: 2022-04-01 16:43:27
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


for _ in range(int(input())):
    n, D, X, Y = map(int, input().split())
    x, y = 0, 0
    d = exgcd(D, n)
    if (Y - X) % d == 0:
        x *= (Y - X) // d
        n //= d
        print(x % n)
    else:
        print("Impossible")
