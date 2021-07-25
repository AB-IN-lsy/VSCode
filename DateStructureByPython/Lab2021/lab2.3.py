'''
Description: https://blog.csdn.net/qq_45859188
Author: NEFU AB_IN
version: 1.0
Date: 2021-05-15 19:37:06
LastEditors: NEFU AB_IN
LastEditTime: 2021-05-21 13:03:40
'''
import datetime
class Product:
    def __init__(self, id, name, price, release_date, rating):
        self.id = id
        self.name = name
        self.price = price
        self.release_date = datetime.datetime.strptime(release_date,'%Y-%m-%d')
        self.rating = rating
    
    def __repr__(self):
        return '{}'.format(self.id)

def merge(a, l, s, r):
    i = l
    j = s + 1
    k = l
    lst = [i.id for i in a]
    rate = [i.rating for i in a]
    t = [i for i in a]
    print(f"Merge {lst[i:s]} and {lst[s:r+1]}")
    while i <= s and j <= r:
        if rate[i] >= rate[j]:
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
    lst = [i.id for i in a]
    print(f"After merge: {lst[l:r+1]}")
    


def merge_sort(a, l, r):
    if l < r:
        m = (l + r) // 2
        merge_sort(a, l, m)
        merge_sort(a, m + 1, r)
        merge(a, l, m, r)


database = [
    Product(1, 'A', 5000, '2019-10-24', 4.7),
    Product(2, 'B', 300, '2018-1-14', 3.1),
    Product(3, 'C', 1200, '2020-3-3', 5),
    Product(4, 'D', 10, '2019-7-19', 4.2),
    Product(5, 'E', 50, '2019-12-4', 3.5),
    Product(6, 'F', 180, '2021-3-8', 3.9)
]

merge_sort(database, 0, len(database)-1)
