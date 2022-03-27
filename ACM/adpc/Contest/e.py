'''
Author: NEFU AB-IN
Date: 2022-03-27 09:08:24
FilePath: \ACM\Contest\e.py
LastEditTime: 2022-03-27 09:09:48
'''
from msvcrt import kbhit

k, n = map(int, input().split())

for i in range(n):
    k += k // 10
    k += 5

print(k)