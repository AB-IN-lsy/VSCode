'''
Author: NEFU AB-IN
Date: 2022-05-22 21:47:55
FilePath: \ACM\Acwing\1927.py
LastEditTime: 2022-05-22 22:10:06
'''
import sys

sys.setrecursionlimit(int(2e9))

from collections import Counter

N = 1000010
son = [[0] * 26 for _ in range(N)]
cnt, idx = [0] * N, 0


def insert(s):
    global idx
    p = 0
    for i in range(len(s)):
        u = ord(s[i]) - ord('a')
        if not son[p][u]:
            idx += 1
            son[p][u] = idx
        p = son[p][u]
    cnt[p] += 1


def query(s):  # 查询前缀是否存在即可
    p = 0
    for i in range(len(s)):
        u = ord(s[i]) - ord('a')
        if not son[p][u]:
            return 0
        p = son[p][u]
    return p


ans = []


# p 代表根节点，s 代表组成的串
def dfs(p, s):
    global ans
    if cnt[p]:
        ans.append(s)
    for i in range(26):
        if son[p][i]:
            ss = s + chr(i + ord('a'))
            dfs(son[p][i], ss)


d = Counter()
w, n = map(int, input().split())

for i in range(1, w + 1):
    s = input()
    d[s] = i
    insert(s)

for i in range(n):
    num, pre = input().split()
    num = int(num)

    p = query(pre)
    if not p:
        print(-1)
        continue

    dfs(p, pre)
    ans.sort()
    # 如果超范围了，或者无自动补全
    if num > len(ans) or d[ans[num - 1]] == 0:
        print(-1)
        continue

    print(d[ans[num - 1]])

    ans = []
