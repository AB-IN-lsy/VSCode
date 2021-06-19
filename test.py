'''
Description: file content
Author: NEFU AB_IN
version: 1.0
Date: 2021-01-28 23:02:48
LastEditors: NEFU AB_IN
LastEditTime: 2021-06-18 20:07:10
'''

l = map(int, input().split())
for i in l:
    print(bin(i)[2:])