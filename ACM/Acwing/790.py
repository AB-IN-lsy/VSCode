'''
Author: NEFU AB-IN
Date: 2022-02-20 14:48:31
FilePath: \ACM\Acwing\790.py
LastEditTime: 2022-02-20 14:49:57
'''

x = float(input())

l, r = -23.0, 23.0
while r - l > 1e-8:
    mid = (l + r) / 2
    if mid**3 >= x:
        r = mid
    else:
        l = mid

print(f'{r:.6f}')