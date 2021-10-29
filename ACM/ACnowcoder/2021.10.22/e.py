'''
Author: NEFU AB-IN
Date: 2021-10-22 22:15:19
FilePath: \ACM\ACnowcoder\2021.10.22\e.py
LastEditTime: 2021-10-29 10:52:54
'''
N = 110

n, m = map(int, input().split())
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

array = [[0 for i in range(N)] for i in range(N)]

x = 0
y = 0
d = 0

for i in range(1, n * m + 1):
    array[x][y] = i
    a = x + dx[d]
    b = y + dy[d]
    if a < 0 or b < 0 or a > n - 1 or b > m - 1 or array[a][b]:
        d = (d + 1) % 4
        a = x + dx[d]
        b = y + dy[d]
    x = a
    y = b
for i in range(n):
    for j in range(m):
        print(array[i][j], end=" ")
    print()
