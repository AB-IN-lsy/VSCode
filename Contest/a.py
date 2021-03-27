'''
Description: https://blog.csdn.net/qq_45859188
Author: NEFU AB_IN
version: 1.0
Date: 2021-03-08 20:28:04
LastEditors: NEFU AB_IN
LastEditTime: 2021-03-25 17:27:00
'''
import math

n = 10000000000000000000000000000
a = 3 * math.log(n) +2000 * n
b = pow(10, -20) * n * n * n
c = pow(math.log(n, 3), 5)
d = math.log(n) ** 2 + 4 * math.log(n) - 1

print(a, b, c, d)