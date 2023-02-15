'''
Author: NEFU AB-IN
Date: 2022-02-16 14:57:13
FilePath: \ACM\Acwing\785.py
LastEditTime: 2022-02-16 15:09:52
'''

a = []


def quicksort(l, r):
    if l >= r:
        return
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
    quicksort(l, j)
    quicksort(j + 1, r)


if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))
    quicksort(0, n - 1)
    for i in a:
        print(i, end=" ")
