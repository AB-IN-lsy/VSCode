'''
Author: NEFU AB-IN
Date: 2022-03-10 21:30:59
FilePath: \ACM\Acwing\876.py
LastEditTime: 2022-03-10 21:31:00
'''
for _ in range(int(input())):
    a, p = map(int, input().split())
    if a % p == 0:
        print("impossible")
    else:
        print(pow(a, p - 2, p))