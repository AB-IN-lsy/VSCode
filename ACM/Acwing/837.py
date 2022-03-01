'''
Author: NEFU AB-IN
Date: 2022-03-01 18:40:18
FilePath: \ACM\Acwing\837.py
LastEditTime: 2022-03-01 19:09:25
'''
N = int(1e5 + 10)

fa = [_ for _ in range(N)]
size = [1 for _ in range(N)]


def find(x):
    if fa[x] != x:
        fa[x] = find(fa[x])
    return fa[x]


n, m = map(int, input().split())
for i in range(m):
    lst = input().split()
    if lst[0] == 'C':
        a, b = int(lst[1]), int(lst[2])
        if find(a) == find(b):
            continue
        size[find(b)] += size[find(a)]
        fa[find(a)] = find(b)
    elif lst[0] == 'Q1':
        a, b = int(lst[1]), int(lst[2])
        if find(a) == find(b):
            print("Yes")
        else:
            print("No")
    else:
        a = int(lst[1])
        print(size[find(a)])
