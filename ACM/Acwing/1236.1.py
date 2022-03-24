'''
Author: NEFU AB-IN
Date: 2022-03-24 17:57:24
FilePath: \ACM\Acwing\1236.1.py
LastEditTime: 2022-03-24 18:54:55
'''
import bisect

n = int(input())
l1 = list(map(int, input().split()))
l2 = list(map(int, input().split()))
l3 = list(map(int, input().split()))
l1.sort()
l3.sort()
ret = 0
print(bisect.bisect_left(l1, 2))
print(bisect.bisect_right(l3, 2))
for i in range(n):
    # print()
    ret += (bisect.bisect_left(l1,
                               l2[i])) * (n - bisect.bisect_right(l3, l2[i]))
print(ret)