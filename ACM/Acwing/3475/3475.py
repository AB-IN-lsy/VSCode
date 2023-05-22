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
read = lambda: map(int, input().split())
LTN = lambda x: ord(x.upper()) - 65  # A -> 0
NTL = lambda x: ascii_uppercase[x]  # 0 -> A

# —————————————————————Division line ——————————————————————

while True:
    try:
        st = input()
        if st == 'ENDOFINPUT':
            break
        s = input()
        ed = input()

        for i in s:
            if i >= 'A' and i <= 'Z':
                ii = NTL((LTN(i) - 5 + 26) % 26)
                print(ii, end="")
            else:
                print(i, end="")
        print()

    except:
        break