'''
Author: NEFU AB-IN
Date: 2022-01-16 12:07:46
FilePath: \ACM\Acwing\1945.py
LastEditTime: 2022-01-16 22:34:58
'''
from bisect import bisect_left, bisect_right

n = int(input())
lst = []


def erfen1(j, x):
    l = j
    r = n - 1
    while l < r:
        mid = l + r >> 1
        if lst[mid] >= x:
            r = mid
        else:
            l = mid + 1
    return r


def erfen2(j, x):
    l = j
    r = n - 1
    while l < r:
        mid = l + r + 1 >> 1
        if lst[mid] <= x:
            l = mid
        else:
            r = mid - 1
    return r


if __name__ == '__main__':
    for i in range(n):
        x = int(input())
        lst.append(x)
    lst.sort()
    res = 0
    for i in range(n - 2):
        for j in range(i + 1, n - 1):
            x = lst[j] - lst[i]
            k1 = bisect_left(lst, lst[j] + x)
            k2 = bisect_right(lst, lst[j] + 2 * x)
            res += (k2 - k1)
            # k1 = erfen1(j + 1, lst[j] + x)
            # k2 = erfen2(j + 1, lst[j] + 2 * x)
            # if lst[k1] >= lst[j] + x and lst[k2] <= lst[j] + 2 * x:
            #     res += (k2 - k1 + 1)
    print(res)