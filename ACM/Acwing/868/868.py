'''
Author: NEFU AB-IN
Date: 2022-03-09 20:14:11
FilePath: \ACM\Acwing\868.py
LastEditTime: 2022-03-09 20:37:11
'''
from math import log

N = int(1e6 + 10)
prime, st, ans = [0] * N, [0] * N, [0] * N


def init():
    cnt = 0
    for i in range(2, N):
        if st[i] == 0:
            prime[cnt] = i
            cnt += 1
            for j in range(i + i, N, i):
                st[j] = 1
        ans[i] = cnt


init()
n = int(input())
print(ans[n])

# print(n / log(n))