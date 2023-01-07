'''
Author: NEFU AB-IN
Date: 2023-01-06 10:02:20
FilePath: \GPLT\A1023\A1023.py
LastEditTime: 2023-01-06 17:59:30
'''
from collections import Counter

n = input()
n2 = str(int(n) * 2)

d1 = Counter(n)
d2 = Counter(n2)

if d1 == d2:
    print("Yes")
else:
    print("No")

print(n2)