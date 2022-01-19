'''
Author: NEFU AB-IN
Date: 2022-01-11 21:07:15
FilePath: \ACM\LanQiao\2021C.py
LastEditTime: 2022-01-11 22:56:44
'''

n = 2021041820210418
lst = []
i = 2
while i * i <= n:
    while n % i == 0:
        n //= i
        lst.append(i)
    i += 1
if n > 1:
    lst.append(n)

print(lst)
