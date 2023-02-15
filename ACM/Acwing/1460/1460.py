'''
Author: NEFU AB-IN
Date: 2022-02-14 18:15:29
FilePath: \ACM\Acwing\1460.py
LastEditTime: 2022-02-14 20:16:51
'''

from collections import Counter

N = 155
P, MOD = 131, 1 << 64

p = [0] * N
h = [0] * N

p[0] = 1

d = Counter()


def get(l, r):
    return (h[r] - h[l - 1] * p[r - l + 1]) % MOD


def check(x):
    for i in range(1, n + 1):
        if i + x - 1 > n:
            break
        ss = get(i, i + x - 1)
        if d[ss]:
            return True
        d[ss] += 1
    return False


if __name__ == "__main__":
    n = int(input())
    s = input()

    s = " " + s
    for i in range(1, n + 1):
        p[i] = p[i - 1] * P % MOD
        h[i] = (h[i - 1] * P + ord(s[i])) % MOD

    l = 1
    r = n
    while l < r:
        mid = l + r + 1 >> 1
        if check(mid):
            l = mid
        else:
            r = mid - 1
    print(r + 1)