'''
Author: NEFU AB-IN
Date: 2022-02-22 14:54:12
FilePath: \ACM\Acwing\797.py
LastEditTime: 2022-02-22 15:03:25
'''
N = int(1e5 + 10)

a = [0] * N
b = [0] * N

n, m = map(int, input().split())
a[1:] = list(map(int, input().split()))

for i in range(1, n + 1):
    b[i] = a[i] - a[i - 1]

for i in range(m):
    l, r, c = map(int, input().split())
    b[l] += c
    b[r + 1] -= c

for i in range(1, n + 1):
    b[i] += b[i - 1]
    print(b[i], end=" ")
