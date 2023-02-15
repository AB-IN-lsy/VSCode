'''
Author: NEFU AB-IN
Date: 2022-03-10 21:01:03
FilePath: \ACM\Acwing\875.py
LastEditTime: 2022-03-10 21:01:03
'''


def qpow(a, b, p):
    res = 1
    while b:
        if b & 1:
            res = res * a % p
        b >>= 1
        a = a * a % p
    return res


for _ in range(int(input())):
    a, b, p = map(int, input().split())
    print(qpow(a, b, p))