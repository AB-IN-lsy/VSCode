'''
Author: NEFU AB-IN
Date: 2021-11-05 19:16:12
FilePath: \ACM\test.py
LastEditTime: 2022-01-09 11:38:49
'''
import bisect

a = [11, 12, 13, 14, 15]

print(bisect.bisect_left(a, 13))
print(bisect.bisect_right(a, 13))
