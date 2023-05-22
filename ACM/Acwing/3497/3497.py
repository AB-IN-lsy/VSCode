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
N = int(1e7 + 10)
INF = int(2e9)

# Define
sys.setrecursionlimit(INF)
input = lambda: sys.stdin.readline().rstrip("\r\n")  # Remove when Mutiple data
read = lambda: map(int, input().split())
letterTonumber = lambda x: ord(x.upper()) - 64

# —————————————————————Division line ——————————————————————

st, prime = [0] * N, [0] * N
cnt = 0


def init():
    global cnt
    for i in range(2, N):
        if not st[i]:
            prime[cnt] = i
            cnt += 1
        j = 0
        while prime[j] * i < N:
            st[prime[j] * i] = 1
            if i % prime[j] == 0:
                break
            j += 1


init()
while True:
    try:
        n, = read()
        print(prime[n - 1])
    except:
        break