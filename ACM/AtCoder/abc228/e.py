'''
Author: NEFU AB-IN
Date: 2022-03-08 13:39:02
FilePath: \ACM\AtCoder\abc228\e.py
LastEditTime: 2022-03-08 15:43:01
'''
MOD = 998244353


def qpow(a, b, p):
    res = 1
    while b:
        if b & 1:
            res = res * a % p
        b >>= 1
        a = a * a % p
    return res


n, k, m = map(int, input().split())

# m ^ k ^ n
if m % MOD == 0:
    print(0)
    exit(0)

print(qpow(m, qpow(k, n, MOD - 1), MOD) % MOD)
