'''
Author: NEFU AB-IN
Date: 2022-04-18 21:21:37
FilePath: \ACM\GPLT\2022MoNi\L2-3.PY
LastEditTime: 2022-04-18 22:42:43
'''
import sys

sys.setrecursionlimit(int(2e9))

from collections import Counter, deque

lt, rt, pos = Counter(), Counter(), Counter()
N = 100


def bulid(il, ir, pl, pr):
    root = postorder[pr]
    k = pos[root]
    prr = k - 1 - il + pl
    if il < k:
        lt[root] = bulid(il, k - 1, pl, prr)
    if ir > k:
        rt[root] = bulid(k + 1, ir, prr + 1, pr - 1)
    return root


ans = [[] for _ in range(N)]


def bfs(root):
    global ans
    mx = 0
    q = deque()
    q.appendleft([root, 0])
    while q:
        root, deep = q.pop()
        ans[deep].append(root)
        if lt.get(root):
            q.appendleft([lt[root], deep + 1])
        if rt.get(root):
            q.appendleft([rt[root], deep + 1])
        mx = max(mx, deep)
    return mx


n = int(input())
inorder = list(map(int, input().split()))
for i in range(n):
    pos[inorder[i]] = i
postorder = list(map(int, input().split()))

root = bulid(0, n - 1, 0, n - 1)
deep = bfs(root)

print("R: ", end="")
for i in range(deep + 1):
    print(ans[i][-1], end=" " if i < deep else "")
print()
print("L: ", end="")
for i in range(deep + 1):
    print(ans[i][0], end=" " if i < deep else "")
