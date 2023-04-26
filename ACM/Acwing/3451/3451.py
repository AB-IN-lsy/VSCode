'''
Author: NEFU AB-IN
Date: 2023-04-26 17:27:09
FilePath: \Acwing\3451\3451.py
LastEditTime: 2023-04-26 18:08:34
'''
# import
import sys, math
from collections import Counter, deque
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from bisect import bisect_left, bisect_right
from datetime import datetime, timedelta
from string import ascii_lowercase, ascii_uppercase


class sa:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __lt__(self, x):
        pass


# Final
N = int(1e3 + 10)
INF = int(2e9)

# Define
sys.setrecursionlimit(INF)
input = lambda: sys.stdin.readline().rstrip("\r\n")  # Remove when Mutiple data
read = lambda: map(int, input().split())
letterTonumber = lambda x: ord(x.upper()) - 64

# —————————————————————Division line ——————————————————————

while True:
    try:
        s = input()

        lsts = [[] for _ in range(27)]

        for i in s:
            if i.isalpha():
                index = letterTonumber(i)
                lsts[index].append(i)

        ans = []
        for lst in lsts:
            for i in lst:
                ans.append(i)

        ans = ans[::-1]

        ss = ""
        for i in range(len(s)):
            if s[i].isalpha():
                ss = ss + ans.pop()
            else:
                ss = ss + s[i]

        print(ss)
    except:
        break