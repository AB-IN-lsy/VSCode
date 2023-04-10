# AB-IN AK Lanqiao !!
import sys, math
from collections import Counter, deque, defaultdict
from bisect import bisect_left, bisect_right
from heapq import heappop, heappush, heapify
from typing import *
from datetime import datetime, timedelta

N = int(1e6 + 10)
INF = int(2e9)
MOD = 998244353

sys.setrecursionlimit(INF)
read = lambda : map(int, input().split())

class sa:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def __lt__(self, x):
        pass

# ---------------divrsion line ----------------
# 感觉像数位dp，先打DFS暴力
# 想不出递推式 就优化暴力吧

n, m = read()

ji = ["1", "3", "5", "7", "9"]
ou = ["0", "2", "4", "6", "8"]
stji, stou = [0] * 5, [0] * 5
ans = 0

def dfs(s, d):
    global ans
    if d == n + 1:
        ans = (ans + 1) % MOD
        return

    for i in range(5):
        if d % 2 == 1:
            cnt = int(ji[i])
            for j in range(max(1, d - 4), d):
                cnt += int(s[j])
            if cnt <= m:
                dfs(s + ji[i], d + 1)
        if d % 2 == 0:
            cnt = int(ou[i])
            for j in range(max(1, d - 4), d):
                cnt += int(s[j])
            if cnt <= m:
                dfs(s + ou[i], d + 1)
    return  


dfs(" ", 1)
print(ans % MOD)