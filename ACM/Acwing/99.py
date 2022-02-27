'''
Author: NEFU AB-IN
Date: 2022-02-22 22:58:59
FilePath: \ACM\Acwing\99.py
LastEditTime: 2022-02-23 09:55:02
'''
N = int(5e3 + 10)

a = [[0] * N for _ in range(N)]
s = [[0] * N for _ in range(N)]

n, r = map(int, input().split())

r = min(r, 5001)

xx, yy, cnt = r, r

for i in range(n):
    x, y, w = map(int, input().split())
    a[x + 1][y + 1] += w
    xx = max(xx, x + 1)
    yy = max(yy, y + 1)

for i in range(1, xx + 1):
    for j in range(1, yy + 1):
        s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j]

res = 0
for i in range(r, xx + 1):
    for j in range(r, yy + 1):
        x1, y1, x2, y2 = i - r + 1, j - r + 1, i, j
        res = max(
            res, s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1])
print(res)