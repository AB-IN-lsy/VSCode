'''
Author: NEFU AB-IN
Date: 2022-01-16 00:23:00
FilePath: \ACM\Acwing\tempCodeRunnerFile.py
LastEditTime: 2022-04-01 17:42:37
'''


def gcd2(a, b):
    if a < b: a, b = b, a
    return gcd2(b, a - b) if b else a


print(gcd2(6, 10))