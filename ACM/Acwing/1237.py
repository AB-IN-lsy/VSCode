'''
Author: NEFU AB-IN
Date: 2022-03-28 17:12:13
FilePath: \ACM\Acwing\1237.py
LastEditTime: 2022-03-28 17:57:25
'''
x, y = map(int, input().split())

k = max(abs(x), abs(y))
if x >= y:
    print(4 * k * k + abs(x - k) + abs(y - k))
else:
    print(4 * k * k - abs(x - k) - abs(y - k))