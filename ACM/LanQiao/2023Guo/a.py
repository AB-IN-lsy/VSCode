from sys import setrecursionlimit, stdin, stdout, exit
from collections import Counter, deque
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from bisect import bisect_left, bisect_right
from datetime import datetime, timedelta
from string import ascii_lowercase, ascii_uppercase
from math import log, ceil, gcd, sqrt, fabs


class sa:
    def __init__(self, x , y):
        self.x = x
        self.y = y
    def __lt__(self, a):
        return self.x < a.x
        


N = int(2e5 + 10)
M = 20
INF = int(2e9)

setrecursionlimit(INF)
input = lambda: stdin.readline().rstrip("\r\n")
read = lambda: map(int, input().split())
LTN = lambda x: ord(x.upper()) - 65
NTL = lambda x: ascii_uppercase[x]
AR = lambda x: [x] * N

# _____________________________________________________

def check(st):
    if str(st.year).count("1") or str(st.month).count("1") or str(st.day).count("1") or str(st.weekday() + 1).count("1"):
        return True
    else:
        return False


st = datetime(year=2023, month=1, day=1)
ans = 0
while st.year == 2023:
    # print(st.date())
    if check(st):
        ans += 5
    else:
        ans += 1
    st = st + timedelta(days=1)
    

print(ans)

