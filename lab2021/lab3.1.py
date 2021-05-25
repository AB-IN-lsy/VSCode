'''
Description: file content
Author: NEFU AB_IN
version: 1.0
Date: 2021-05-21 08:12:31
LastEditors: NEFU AB_IN
LastEditTime: 2021-05-21 18:49:00
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


def get_topk(database, k):
    database.reverse()
    QuickSelect(database, 0, len(database) - 1, k)
    return database[len(database) - k:]

def partition(database, l, r, p):
    tmp = l
    l += 1
    while l <= r:
        while l <= r and database[l].rating < p:
                l += 1
        while l <= r and database[r].rating > p:
                r -= 1
        if l <= r:
            database[l], database[r] = database[r], database[l]
            l += 1
            r -= 1
    database[tmp], database[r] = database[r], database[tmp]
    return r


def QuickSelect(database, l, r, k):
    if l <= r:
        p = database[l].rating
        index = partition(database, l, r, p)
        if index == len(database) - k:
            return
        elif index < len(database) - k:
            QuickSelect(database, index + 1, r, k)
        else:   
            QuickSelect(database, l, index - 1, k)

	
database = [
    Product(11, 'A', 5000, '2019-10-24', 4.7),
    Product(21, 'B', 300, '2018-1-14', 3.1),
    Product(31, 'C', 1200, '2020-3-3', 5),
    Product(41, 'D', 10, '2019-7-19', 4.2),
    Product(54, 'E', 50, '2019-12-4', 3.5),
    Product(63, 'F', 180, '2021-3-8', 3.9),
    Product(77, 'G', 100, '2020-7-19', 4.3),
    Product(83, 'H', 250, '2019-2-14', 2.7),
    Product(92, 'I', 20, '2017-8-13', 3.5)
]
topk = get_topk(database, 2)
topk.sort(key=lambda x:x.rating, reverse=True)
for d in topk:
    print('{}, {}'.format(d, d.rating))