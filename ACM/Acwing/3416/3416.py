'''
Author: NEFU AB-IN
Date: 2022-03-21 15:43:14
FilePath: \ACM\Acwing\3416.py
LastEditTime: 2022-03-21 15:43:15
'''
n = int(input()) // 1000

n = n % 86400

h = n // 3600
n %= 3600
m = n // 60
s = n % 60

print(f"{h:02}:{m:02}:{s:02}")
