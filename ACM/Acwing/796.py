'''
Author: NEFU AB-IN
Date: 2022-02-22 15:24:00
FilePath: \ACM\Acwing\796.py
LastEditTime: 2022-02-22 15:34:28
'''
N = int(1e3 + 100)

a = [[0] * N for _ in range(N)]

n, m, q = map(int, input().split())

for i in range(1, n + 1):
    a[i][1:] = list(map(int, input().split()))

for i in range(1, n + 1):
    for j in range(1, m + 1):
        a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1]

for i in range(q):
    x1, y1, x2, y2 = map(int, input().split())
    print(a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1])