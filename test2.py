'''
Description: https://blog.csdn.net/qq_45859188
Author: NEFU AB_IN
version: 1.0
Date: 2021-03-14 09:56:33
LastEditors: NEFU AB_IN
LastEditTime: 2021-03-14 11:43:19
'''
n = int(input())
n -= 1
if n == 0:
	print(1)
elif n <= 9:
    tmp = (n * (n + 1) // 2)
    print(tmp * 11)
