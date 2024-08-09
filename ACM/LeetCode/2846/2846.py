# 3.8.19 import
import random
from collections import Counter, defaultdict, deque
from datetime import datetime, timedelta
from functools import lru_cache
from heapq import heapify, heappop, heappush, nlargest, nsmallest
from itertools import combinations, compress, permutations, starmap, tee
from math import ceil, comb, fabs, floor, gcd, hypot, log, perm, sqrt
from string import ascii_lowercase, ascii_uppercase
from sys import exit, setrecursionlimit, stdin
from typing import Any, Dict, List, Optional, Tuple, TypeVar, Union

# Constants
TYPE = TypeVar('TYPE')
N = int(2e5 + 10)
M = int(20)
INF = int(1e12)
OFFSET = int(100)
MOD = int(1e9 + 7)

# Set recursion limit
setrecursionlimit(int(2e9))


class Arr:
    array = staticmethod(lambda x=0, size=N: [x() if callable(x) else x for _ in range(size)])
    array2d = staticmethod(lambda x=0, rows=N, cols=M: [Arr.array(x, cols) for _ in range(rows)])
    graph = staticmethod(lambda size=N: [[] for _ in range(size)])


class Math:
    max = staticmethod(lambda a, b: a if a > b else b)
    min = staticmethod(lambda a, b: a if a < b else b)


class IO:
    input = staticmethod(lambda: stdin.readline().rstrip("\r\n"))
    read = staticmethod(lambda: map(int, IO.input().split()))
    read_list = staticmethod(lambda: list(IO.read()))


class Std:
    class LCA:
        """Useing TreeAncestor calculate LCA"""

        def __init__(self, edges: List[List[int]]):
            n = len(edges) + 1
            m = n.bit_length()
            g = Arr.graph(n)
            cnt_ = Arr.array2d(Counter, n, m)

            for x, y, w in edges:  # Node indices start from 0
                g[x].append((y, w))
                g[y].append((x, w))

            depth = Arr.array(0, n)
            pa = Arr.array2d(-1, n, m)

            def dfs(x: int, fa: int) -> None:
                """Depth-first search to initialize the ancestor table and depth array."""
                pa[x][0] = fa  # init itself
                for y, w in g[x]:
                    if y != fa:
                        depth[y] = depth[x] + 1
                        cnt_[y][0][w] = 1
                        dfs(y, x)
            dfs(0, -1)

            for i in range(m - 1):
                for x in range(n):
                    p = pa[x][i]  # Get the 2^i-th ancestor of node x
                    if p != -1:
                        pp = pa[p][i]  # Get the 2^i-th ancestor of p, which will be the 2^(i+1)-th ancestor of x
                        pa[x][i + 1] = pp  # Set the 2^(i+1)-th ancestor of x
                        cnt_[x][i + 1] = cnt_[x][i] + cnt_[p][i]
            self.depth = depth
            self.pa = pa
            self.cnt_ = cnt_

        def get_kth_ancestor(self, node: int, k: int, cnt_: Counter) -> int:
            """Returns the k-th ancestor of the given node (The starting node). That is, jump up k steps"""
            for i in range(k.bit_length()):
                if (k >> i) & 1:
                    node_new = self.pa[node][i]
                    cnt_ += self.cnt_[node][i]
                    node = node_new
            return node

        def get_lca(self, x: int, y: int):
            """Returns the Lowest Common Ancestor (LCA) of nodes x and y."""
            cnt_ = Counter()
            if self.depth[x] > self.depth[y]:
                x, y = y, x
            # Bring y and x to the same depth
            y = self.get_kth_ancestor(y, self.depth[y] - self.depth[x], cnt_)
            if y == x:
                return x, max(cnt_.values()) if cnt_ else 0
            for i in range(len(self.pa[x]) - 1, -1, -1):
                px, py = self.pa[x][i], self.pa[y][i]
                if px != py:
                    cnt_ += self.cnt_[x][i]
                    cnt_ += self.cnt_[y][i]
                    x, y = px, py  # Move both nodes up by 2^i steps

            cnt_ += self.cnt_[x][0]
            cnt_ += self.cnt_[y][0]
            return self.pa[x][0], max(cnt_.values()) if cnt_ else 0  # Return the parent of x (or y) as LCA


# ————————————————————— Division line ——————————————————————
class Solution:
    def minOperationsQueries(self, n: int, edges: List[List[int]], queries: List[List[int]]) -> List[int]:
        lca = Std.LCA(edges)
        ans = []
        for a, b in queries:
            path_len = lca.depth[a] + lca.depth[b]
            lca_ans, max_len = lca.get_lca(a, b)
            path_len -= lca.depth[lca_ans] * 2
            ans.append(path_len - max_len)
        return ans


Solution().minOperationsQueries(7, [[0, 1, 1], [1, 2, 1], [2, 3, 1], [3, 4, 2], [4, 5, 2], [5, 6, 2]], [[0, 3], [3, 6], [2, 6], [0, 6]])
