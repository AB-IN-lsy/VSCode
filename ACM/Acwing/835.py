'''
Author: NEFU AB-IN
Date: 2022-02-28 23:16:38
FilePath: \ACM\Acwing\835.py
LastEditTime: 2022-02-28 23:32:18
'''

N = int(1e6 + 10)

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


def query(s):
    p = 0
    for i in range(len(s)):
        u = ord(s[i]) - ord('a')
        if not son[p][u]:
            return 0
        p = son[p][u]
    return cnt[p]


n = int(input())
for i in range(n):
    op, s = input().split()

    if op == 'I':
        insert(s)
    else:
        print(query(s))