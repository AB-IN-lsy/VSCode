'''
Author: NEFU AB-IN
Date: 2023-06-09 15:54:35
FilePath: \LanQiao\3321\3321.py
LastEditTime: 2023-06-09 16:10:50
'''
# import
from sys import setrecursionlimit, stdin, stdout, exit
from collections import Counter, deque
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from bisect import bisect_left, bisect_right
from datetime import datetime, timedelta
from string import ascii_lowercase, ascii_uppercase
from math import log, gcd, sqrt, fabs, ceil, floor


class sa:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __lt__(self, a):
        return self.x < a.x


# Final
N = int(2e6 + 10)
M = 20
INF = int(2e9)

# Define
setrecursionlimit(INF)
input = lambda: stdin.readline().rstrip("\r\n")  # Remove when Mutiple data
read = lambda: map(int, input().split())
LTN = lambda x: ord(x.upper()) - 65  # A -> 0
NTL = lambda x: ascii_uppercase[x]  # 0 -> A

# —————————————————————Division line ——————————————————————
st, prime = [0] * N, [0] * N
cnt = 0


def init():
    global cnt
    st[0] = st[1] = 1
    for i in range(2, N):
        if st[i] == 0:
            prime[cnt] = i
            cnt += 1
        j = 0
        while i * prime[j] < N:
            st[i * prime[j]] = 1
            if i % prime[j] == 0:
                break
            j += 1
    for i in range(1, N):
        st[i] += st[i - 1]


init()
a, b, k = read()
if k > b - a + 1:
    print(-1)
    exit(0)


def check(x):
    for i in range(a, b + 1):
        l, r = i, i + x - 1
        if r > b:
            break
        if st[r] - st[l - 1] > (r - l + 1) - k:
            return False
    return True


l, r = 1, b - a + 1
while l < r:
    mid = l + r >> 1
    if check(mid):
        r = mid
    else:
        l = mid + 1

if check(l):
    print(l)
else:
    print(-1)