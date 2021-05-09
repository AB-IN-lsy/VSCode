'''
Description: https://blog.csdn.net/qq_45859188
Author: NEFU AB_IN
version: 1.0
Date: 2021-03-08 20:28:04
LastEditors: NEFU AB_IN
LastEditTime: 2021-05-05 12:27:06
'''
l = list()
for n in range(100):
    i = 1
    j = 1
    b = set()
    while n - 2 * i >= 0:
        b.add(2 * l[n - i] - l[n - 2 * i])
        i += 1
        while j in b:
            b.remove(j)
            j += 1
            l.append(j)
print(*l)