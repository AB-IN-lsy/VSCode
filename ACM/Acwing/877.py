'''
Author: NEFU AB-IN
Date: 2022-03-11 14:19:44
FilePath: \ACM\Acwing\877.py
LastEditTime: 2022-03-11 14:27:56
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
    a, b = map(int, input().split())
    x, y = 0, 0
    exgcd(a, b)
    print(x, y)