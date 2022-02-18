'''
Author: NEFU AB-IN
Date: 2022-02-18 15:25:02
FilePath: \ACM\Acwing\788.py
LastEditTime: 2022-02-18 15:48:43
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
            res += r - j + 1
        else:
            tmp.append(a[j])
            j += 1
    tmp += a[i:mid + 1]
    tmp += a[j:r + 1]
    a[l:r + 1] = tmp
    return res


n = int(input())
a = list(map(int, input().split()))

print(n * (n - 1) // 2 - merge(0, n - 1))