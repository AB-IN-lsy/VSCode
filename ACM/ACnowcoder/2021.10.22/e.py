'''
Author: NEFU AB-IN
Date: 2021-10-22 22:15:19
FilePath: \ACM\ACnowcoder\2021.10.22\e.py
LastEditTime: 2021-10-22 22:25:52
'''
n = input()
lst = list(map(int, input().split()))
for s in lst:
    s = bin(s)[2:]
    s = s[::-1]
    print(int(s, 2))
