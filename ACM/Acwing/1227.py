'''
Author: NEFU AB-IN
Date: 2022-03-22 21:27:03
FilePath: \ACM\Acwing\1227.py
LastEditTime: 2022-03-22 21:31:08
'''


def check(x):
    cnt = 0
    for i in range(n):
        cnt += ((a[i][0] // x) * (a[i][1] // x))
    return cnt >= k


n, k = map(int, input().split())
a = []

mx = -1
for i in range(n):
    h, w = map(int, input().split())
    a.append([h, w])
    mx = max(mx, h)
    mx = max(mx, w)

l, r = 1, mx
while l < r:
    mid = l + r + 1 >> 1
    if check(mid):
        l = mid
    else:
        r = mid - 1

print(r)