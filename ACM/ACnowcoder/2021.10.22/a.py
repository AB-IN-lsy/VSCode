'''
Author: NEFU AB-IN
Date: 2021-10-29 10:46:50
FilePath: \ACM\ACnowcoder\2021.10.22\a.py
LastEditTime: 2021-10-29 10:58:29
'''
import itertools as it

n = int(input())
array = [i + 1 for i in range(n)]
for i in it.permutations(array):
    for j in i:
        print(j, end=" ")
    print()
