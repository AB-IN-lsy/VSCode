'''
Author: NEFU AB-IN
Date: 2022-02-18 16:17:54
FilePath: \ACM\Acwing\107.py
LastEditTime: 2022-02-18 16:17:55
'''
a = []


def merge(l, r):
    if l >= r:
        return 0
    mid = l + r >> 1
    res = merge(l, mid) + merge(mid + 1, r)

    i, j = l, mid + 1
    tmp = []
    while i <= mid and j <= r:
        if a[i] <= a[j]:
            tmp.append(a[i])
            i += 1
        else:
            tmp.append(a[j])
            j += 1
            res += mid - i + 1

    tmp += a[i:mid + 1]
    tmp += a[j:r + 1]
    a[l:r + 1] = tmp

    return res


while True:
    n = int(input())
    if n == 0:
        exit(0)
    for i in range(n):
        a.append(int(input()))
    print(merge(0, n - 1))
    a = []