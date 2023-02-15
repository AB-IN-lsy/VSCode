'''
Author: NEFU AB-IN
Date: 2022-03-29 12:40:53
FilePath: \ACM\Acwing\1224.1.py
LastEditTime: 2022-03-29 12:43:46
'''
N = int(1e6 + 10)
fa = [i for i in range(N)]


def find(x):
    if x != fa[x]:
        return find(fa[x])
    return fa[x]


n = int(input())
a = list(map(int, input().split()))
a = [0, *a]

for i in range(1, n + 1):
    x = find(a[i])
    y = find(a[a[i]])
    fa[x] = y

ans = 0
for i in range(1, n + 1):
    if fa[i] == i:
        ans += 1

print(n - ans)