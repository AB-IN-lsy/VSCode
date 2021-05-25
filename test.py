'''
Description: find k-th smallest element
Author: NEFU AB_IN
version: 1.0
Date: 2021-05-21 08:12:31
LastEditors: NEFU AB_IN
LastEditTime: 2021-05-21 18:59:18
'''
def partition(database, l, r, p):
    tmp = l
    l += 1
    while l <= r:
        while l <= r and database[l] > p:
                l += 1
        while l <= r and database[r] < p:
                r -= 1
        if l <= r:
            database[l], database[r] = database[r], database[l]
            l += 1
            r -= 1
    database[tmp], database[r] = database[r], database[tmp]
    return r


def QuickSelect(database, l, r, k):
    if l <= r:
        p = database[l]
        index = partition(database, l, r, p)
        if index == k - 1:
            return
        elif index < k - 1:
            QuickSelect(database, index + 1, r, k)
        else:   
            QuickSelect(database, l, index - 1, k)

database = [1, 4, 7, 5, 2]
k = 3
QuickSelect(database, 0, len(database) - 1, k)
print(database[k - 1])