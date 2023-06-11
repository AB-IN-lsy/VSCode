'''
Author: NEFU AB-IN
Date: 2023-06-09 20:29:03
FilePath: \LanQiao\2940\test.py
LastEditTime: 2023-06-09 20:31:38
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
N = int(1e3 + 10)
M = 20
INF = int(2e9)

# Define
setrecursionlimit(INF)
input = lambda: stdin.readline().rstrip("\r\n")  # Remove when Mutiple data
read = lambda: map(int, input().split())
LTN = lambda x: ord(x.upper()) - 65  # A -> 0
NTL = lambda x: ascii_uppercase[x]  # 0 -> A

# —————————————————————Division line ——————————————————————
cnt = 0
ans = [[1, 2], [3, 5], [4, 7], [5, 8], [2, 7]]

ans.sort()
st, ed = -INF, -INF
for i in range(len(ans)):
    if ed < ans[i][0]:
        if st != -INF and ed != -INF:
            cnt += 1
        st = ans[i][0]
        ed = ans[i][1]
    else:
        ed = max(ed, ans[i][1])
if st != INF and ed != INF:
    cnt += 1
print(cnt)

cnt = 1
ans.sort(key=lambda x: x[1])
tmp = ans[0][1]
for i in ans:
    if i[0] > tmp:
        cnt += 1
        tmp = i[1]
print(cnt)