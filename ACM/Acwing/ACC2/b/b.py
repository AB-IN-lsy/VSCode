'''
Author: NEFU AB-IN
Date: 2023-04-02 19:23:42
FilePath: \Acwing\ACC2\b\b.py
LastEditTime: 2023-04-06 19:56:44
'''
# import
import sys, math, os
from io import BytesIO, IOBase
from collections import Counter, deque, defaultdict
from heapq import heapify, heappop, heappush, heappushpop, nlargest, nsmallest
from bisect import bisect_left, bisect_right
from typing import *


# Fast Read
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


BUFSIZE = 4096


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()


# Final
N = int(1e3 + 10)
INF = int(2e9)

# Define
sys.setrecursionlimit(INF)
sys.stdin = IOWrapper(sys.stdin)
sys.stdout = IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
read = lambda: map(int, input().split())

# —————————————————————Division line ————————————————————————————————————————


def check(n, m):
    while m:
        r = m % n
        if r != 0 and r != 1 and r != n - 1:
            return False
        if r > 1:  # 不能写 r == n - 1 因为n可能为2
            r = -1
        m = (m - r) // n
    return True


n, m = read()
print("YES" if check(n, m) else "NO")
