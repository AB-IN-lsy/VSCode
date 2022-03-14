'''
Author: NEFU AB-IN
Date: 2022-03-12 12:04:31
FilePath: \ACM\Acwing\887.py
LastEditTime: 2022-03-12 12:14:37
'''
N = int(1e5 + 10)


def C(a, b):
    global p
    i, j, res = a, 1, 1
    while j <= b:
        res = res * i % p
        res = res * pow(j, p - 2, p) % p
        i -= 1
        j += 1
    return res


def lucas(a, b):
    if a < p and b < p:
        return C(a, b)
    return C(a % p, b % p) * lucas(a // p, b // p) % p


for i in range(int(input())):
    a, b, p = map(int, input().split())
    print(lucas(a, b))
