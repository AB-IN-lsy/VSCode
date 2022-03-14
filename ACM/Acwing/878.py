'''
Author: NEFU AB-IN
Date: 2022-03-11 15:18:46
FilePath: \ACM\Acwing\878.py
LastEditTime: 2022-03-11 15:18:47
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
    a, b, m = map(int, input().split())
    x, y = 0, 0
    d = exgcd(a, m)
    if b % d == 0:
        print(x * b // d % m)
    else:
        print("impossible")