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


d = Counter(
    {
        0: "1111110",
        1: "0110000",
        2: "1101101",
        3: "1111001",
        4: "0110011",
        5: "1011011",
        6: "1011111",
        7: "1110000",
        8: "1111111",
        9: "1111011"
    }
)

ans = [
    "0000011",
    "1001011",
    "0000001",
    "0100001",
    "0101011",
    "0110110",
    "1111111",
    "0010110",
    "0101001",
    "0010110",
    "1011100",
    "0100110",
    "1010000",
    "0010011",
    "0001111",
    "0101101",
    "0110101",
    "1101010",
]

res = 1
for i in range(len(ans)):
    cnt = 0
    for j in range(10):
        s, t = ans[i], d[j]
        flag = 1
        for k in range(len(s)):
            if s[k] == '1' and t[k] == '0':
                flag = 0
                break
        cnt += flag
    res *= cnt
print(res)
