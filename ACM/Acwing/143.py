'''
Author: NEFU AB-IN
Date: 2022-03-01 10:18:29
FilePath: \ACM\Acwing\143.py
LastEditTime: 2022-03-01 10:56:00
'''
N = int(1e5 + 10)

son = [[0] * 2 for _ in range(N * 31)]
val, a, idx = [0] * (N * 31), [0] * N, 0


def insert(x):
    global idx
    p = 0
    for i in range(30, -1, -1):
        u = x >> i & 1
        if not son[p][u]:
            idx += 1
            son[p][u] = idx
        p = son[p][u]
    val[p] = x


def query(x):
    p = 0
    for i in range(30, -1, -1):
        u = x >> i & 1
        if son[p][u ^ 1]:
            p = son[p][u ^ 1]
        else:
            p = son[p][u]
    return x ^ val[p]


n = int(input())
a = list(map(int, input().split()))
res = 0
for i in range(n):
    insert(a[i])
    res = max(res, query(a[i]))
print(res)