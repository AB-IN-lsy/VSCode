'''
Description: https://blog.csdn.net/qq_45859188
Author: NEFU AB_IN
version: 1.0
Date: 2021-05-15 20:50:34
LastEditors: NEFU AB_IN
LastEditTime: 2021-05-15 20:59:28
'''
def merge(a, l, s, r):
    i = l
    j = s + 1
    k = l
    t = [0 for i in range(len(a))]
    while i <= s and j <= r:
        if a[i] <= a[j]:
            t[k] = a[i]
            i += 1
        else:
            t[k] = a[j]
            j += 1
        k += 1
    while i <= s:
        t[k] = a[i]
        k += 1
        i += 1
    while j <= r:
        t[k] = a[j]
        k += 1
        j += 1
    for i in range(l, r + 1):
        a[i] = t[i]
    
def merge_sort(a, l, r):
    if l < r:
        m = (l + r) // 2
        merge_sort(a, l, m)
        merge_sort(a, m + 1, r)
        merge(a, l, m, r)

a = [1, 3, 2, 4, 5]
merge_sort(a, 0, len(a) - 1)
print(a)