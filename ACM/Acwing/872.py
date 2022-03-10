'''
Author: NEFU AB-IN
Date: 2022-03-10 10:32:35
FilePath: \ACM\Acwing\872.py
LastEditTime: 2022-03-10 10:32:35
'''


def gcd(a, b):
    return gcd(b, a % b) if b else a


for _ in range(int(input())):
    a, b = map(int, input().split())
    print(gcd(a, b))