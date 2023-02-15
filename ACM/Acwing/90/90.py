'''
Author: NEFU AB-IN
Date: 2022-03-01 20:17:12
FilePath: \ACM\Acwing\90.py
LastEditTime: 2022-03-01 20:18:21
'''
a = int(input())
b = int(input())
p = int(input())
res = 0
while b:
    if b & 1:
        res = (res + a) % p
    b >>= 1
    a = a * 2 % p
print(res)