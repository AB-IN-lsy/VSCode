'''
Author: NEFU AB-IN
Date: 2022-02-16 16:15:05
FilePath: \ACM\Acwing\786.py
LastEditTime: 2022-02-16 16:19:42
'''

a = []


def quickselect(l, r, k):
    if l >= r:
        return a[l]
    pivot = a[l + r >> 1]
    i, j = l - 1, r + 1
    while i < j:
        while True:
            i += 1
            if a[i] >= pivot:
                break
        while True:
            j -= 1
            if a[j] <= pivot:
                break
        if i < j:
            a[i], a[j] = a[j], a[i]
    sl = j - l + 1
    if k <= sl:
        return quickselect(l, j, k)
    else:
        return quickselect(j + 1, r, k - sl)


if __name__ == "__main__":
    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    print(quickselect(0, n - 1, k))