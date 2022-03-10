'''
Author: NEFU AB-IN
Date: 2022-03-09 16:08:52
FilePath: \ACM\Acwing\338.py
LastEditTime: 2022-03-09 16:26:28
'''
from math import log10


def count(n, d):  #求从1到数n中数k出现的次数
    len = int(log10(n) + 1) if n > 0 else 0
    res = 0
    for i in range(1, len + 1):  #高位到低位
        # opqrstu ex: i = 4, l = opq, r = sty, di = r
        # xxxdyyy
        p = 10**(len - i)
        l = n // p // 10
        r = n % p
        di = n // p % 10

        # xxx < abc
        if d:
            res += l * p
        else:
            res += (l - 1) * p
        # xxx = abc
        if di == d:
            res += r + 1
        if di > d:
            res += p
    return res


while True:
    try:
        a, b = map(int, input().split())
        if a == 0 and b == 0:
            break
        if a > b:
            a, b = b, a
        for i in range(10):
            print(count(b, i) - count(a - 1, i), end=" ")
        print()
    except:
        break