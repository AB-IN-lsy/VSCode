'''
Author: NEFU AB-IN
Date: 2022-03-21 18:07:08
FilePath: \ACM\Acwing\717.1.py
LastEditTime: 2022-03-21 18:07:08
'''
n = int(input())

a, b = 0, 1

for i in range(n):
    print(a, end=" ")
    fn = a + b
    a, b = b, fn