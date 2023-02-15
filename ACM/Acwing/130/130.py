'''
Author: NEFU AB-IN
Date: 2022-03-12 17:11:05
FilePath: \ACM\Acwing\130.py
LastEditTime: 2022-03-12 17:13:21
'''
from math import factorial as fact

n = int(input())
a = fact(2 * n)
b = fact(n)

print(a // b // b // (n + 1))