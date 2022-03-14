'''
Author: NEFU AB-IN
Date: 2022-03-12 16:50:02
FilePath: \ACM\Acwing\889.py
LastEditTime: 2022-03-12 16:50:03
'''


def C(a, b):
    i, j, res = a, 1, 1
    while j <= b:
        res = res * i % MOD
        res = res * pow(j, MOD - 2, MOD) % MOD
        i -= 1
        j += 1
    return res


MOD = int(1e9 + 7)
n = int(input())
print(C(2 * n, n) * pow(n + 1, MOD - 2, MOD) % MOD)
