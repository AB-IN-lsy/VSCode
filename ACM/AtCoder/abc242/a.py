'''
Author: NEFU AB-IN
Date: 2022-03-05 20:15:31
FilePath: \ACM\AtCoder\abc242\a.py
LastEditTime: 2022-03-05 20:16:45
'''
a, b, c, x = map(int, input().split())
if x <= a:
    print(1)
elif x > a and x <= b:
    print(c / (b - a))
else:
    print(0)