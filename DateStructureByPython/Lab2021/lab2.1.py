'''
Description: https://blog.csdn.net/qq_45859188
Author: NEFU AB_IN
version: 1.0
Date: 2021-05-14 08:15:02
LastEditors: NEFU AB_IN
LastEditTime: 2021-05-14 08:17:16
'''
def insertion_sort_recursion(a, n):
    if n == 1:
        return
    for j in range(len(a) - n + 1, 0, -1):
        if a[j] < a[j - 1]:
            a[j], a[j - 1] = a[j - 1], a[j]
    print(a)
    insertion_sort_recursion(a, n - 1)