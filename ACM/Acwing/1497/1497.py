'''
Author: NEFU AB-IN
Date: 2022-04-18 22:30:26
FilePath: \ACM\Acwing\1497.py
LastEditTime: 2022-04-18 22:32:52
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


def bfs(root):
    q = deque()
    q.appendleft(root)
    while q:
        root = q.pop()
        print(root, end=" ")
        if lt.get(root):
            q.appendleft(lt[root])
        if rt.get(root):
            q.appendleft(rt[root])


n = int(input())
postorder = list(map(int, input().split()))
inorder = list(map(int, input().split()))
for i in range(n):
    pos[inorder[i]] = i

root = bulid(0, n - 1, 0, n - 1)
bfs(root)
