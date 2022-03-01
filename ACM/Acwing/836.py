'''
Author: NEFU AB-IN
Date: 2022-03-01 15:51:43
FilePath: \ACM\Acwing\836.py
LastEditTime: 2022-03-01 16:04:30
'''
N = int(1e5 + 10)
fa = [i for i in range(N)]


def find(x):
    if fa[x] != x:
        fa[x] = find(fa[x])
    return fa[x]


n, m = map(int, input().split())

for i in range(m):
    op, a, b = input().split()
    a, b = int(a), int(b)
    if op == 'M':
        fa[find(a)] = find(b)
    else:
        if find(a) == find(b):
            print("Yes")
        else:
            print("No")