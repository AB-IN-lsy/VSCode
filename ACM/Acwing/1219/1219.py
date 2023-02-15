'''
Author: NEFU AB-IN
Date: 2022-03-25 13:51:27
FilePath: \ACM\Acwing\1219.py
LastEditTime: 2022-03-25 14:02:04
'''


def find(p):
    x, y = (p // w), (p % w)
    if (p // w) & 1:
        y = w - y - 1
    return x, y


w, m, n = map(int, input().split())

xm, ym = find(m - 1)
xn, yn = find(n - 1)

print(abs(xm - xn) + abs(ym - yn))