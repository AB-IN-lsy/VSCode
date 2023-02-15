'''
Author: NEFU AB-IN
Date: 2022-05-16 08:23:19
FilePath: \ACM\Acwing\1921.1.py
LastEditTime: 2022-05-16 08:55:15
'''
N = 110
fa = [i for i in range(N)]
s = [1] * N
a = [0]
b = [0]
idx = [0] * N


def find(x):
    if fa[x] != x:
        fa[x] = find(fa[x])
    return fa[x]


n = int(input())

for i in range(1, n + 1):
    a.append(int(input()))
    idx[a[i]] = i

for i in range(1, n + 1):
    b.append(int(input()))

for i in range(1, n + 1):
    x = idx[i]
    y = idx[b[x]]
    if find(x) != find(y):
        s[find(x)] += s[find(y)]
        fa[find(y)] = find(x)

cnt, ans = 0, -1

for i in range(1, n + 1):
    if fa[i] == i and s[i] > 1:
        cnt += 1
        ans = max(ans, s[i])

print(cnt, ans)