'''
Author: NEFU AB-IN
Date: 2022-02-22 17:09:24
FilePath: \ACM\Acwing\798.py
LastEditTime: 2022-02-22 17:09:25
'''
N = int(1e3 + 10)

a = [[0] * N for _ in range(N)]
b = [[0] * N for _ in range(N)]


def insert(x1, y1, x2, y2, c):
    b[x1][y1] += c
    b[x1][y2 + 1] -= c
    b[x2 + 1][y1] -= c
    b[x2 + 1][y2 + 1] += c


n, m, q = map(int, input().split())

for i in range(1, n + 1):
    a[i][1:] = list(map(int, input().split()))

for i in range(1, n + 1):
    for j in range(1, m + 1):
        insert(i, j, i, j, a[i][j])

for i in range(q):
    x1, y1, x2, y2, c = map(int, input().split())
    insert(x1, y1, x2, y2, c)

for i in range(1, n + 1):
    for j in range(1, m + 1):
        a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + b[i][j]
        print(a[i][j], end=" ")
    print()