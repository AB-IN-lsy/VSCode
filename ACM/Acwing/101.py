'''
Author: NEFU AB-IN
Date: 2022-02-15 14:58:04
FilePath: \ACM\Acwing\101.py
LastEditTime: 2022-02-15 15:22:29
'''
from collections import Counter

N = int(1e5 + 10)
a = [0] * N

d = Counter()

if __name__ == "__main__":
    n, p, h, m = map(int, input().split())
    a[1] = h
    for i in range(m):
        l, r = map(int, input().split())
        if l > r:
            l, r = r, l
        if d[(l, r)] == 0:
            a[l + 1] -= 1
            a[r] += 1
        d[(l, r)] = 1
    for i in range(1, n + 1):
        a[i] += a[i - 1]
        print(a[i])
