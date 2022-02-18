'''
Author: NEFU AB-IN
Date: 2022-02-18 11:33:11
FilePath: \ACM\Acwing\787.py
LastEditTime: 2022-02-18 19:20:56
'''
a = []


def mergesort(l, r):
    if l >= r:
        return
    mid = l + r >> 1
    mergesort(l, mid)
    mergesort(mid + 1, r)
    tmp = []
    i, j = l, mid + 1

    while i <= mid or j <= r:
        if j == r + 1 or i <= mid and a[i] <= a[j]:
            tmp.append(a[i])
            i += 1
        else:
            tmp.append(a[j])
            j += 1
    a[l:r + 1] = tmp


if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))

    mergesort(0, n - 1)
    for i in a:
        print(i, end=" ")
