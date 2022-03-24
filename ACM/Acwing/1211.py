'''
Author: NEFU AB-IN
Date: 2022-03-23 16:31:59
FilePath: \ACM\Acwing\1211.py
LastEditTime: 2022-03-23 16:31:59
'''
N = 55
a = [0] * N

n = int(input())

a = list(map(int, input().split()))

l, r = 0, 0
for i in range(1, n):
    if abs(a[0]) < abs(a[i]) and a[i] < 0:
        r += 1
    if abs(a[0]) > abs(a[i]) and a[i] > 0:
        l += 1

if (a[0] > 0 and r == 0) or (a[0] < 0 and l == 0):
    print(1)
else:
    print(r + l + 1)