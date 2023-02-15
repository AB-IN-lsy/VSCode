'''
Author: NEFU AB-IN
Date: 2022-03-12 12:34:28
FilePath: \ACM\Acwing\888.py
LastEditTime: 2022-03-12 12:34:29
'''


def C(a, b):
    i, j, res = a, 1, 1
    while j <= b:
        res *= i
        res //= j
        i -= 1
        j += 1
    return res


a, b = map(int, input().split())
print(C(a, b))