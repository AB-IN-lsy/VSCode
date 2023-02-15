'''
Author: NEFU AB-IN
Date: 2022-03-22 20:11:59
FilePath: \ACM\Acwing\730.py
LastEditTime: 2022-03-22 20:12:00
'''


def check(e):
    for i in range(n):
        if a[i] > e:
            e -= (a[i] - e)
        else:
            e += (e - a[i])
    return e >= 0


n = int(input())
a = list(map(int, input().split()))

l, r = 0, max(a)
while l < r:
    mid = l + r >> 1
    if check(mid):
        r = mid
    else:
        l = mid + 1
print(r)