'''
Author: NEFU AB-IN
Date: 2022-03-04 18:56:06
FilePath: \ACM\ACnowcoder\2022.3.24\a.py
LastEditTime: 2022-03-04 19:08:30
'''
x, n = map(int, input().split())
if x < n:
    print(x)
    exit(0)
print(n * x)
