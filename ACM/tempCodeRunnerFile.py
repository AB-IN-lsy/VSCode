'''
Author: NEFU AB-IN
Date: 2021-11-05 19:37:21
FilePath: \ACM\tempCodeRunnerFile.py
LastEditTime: 2022-04-21 22:38:56
'''
# Problem: A. Division?
# Contest: Codeforces Round #784 (Div. 4)
# Author: NEFU AB-IN
# Edit Time:2022-04-21 22:36:00
# URL: https://codeforces.com/contest/1669/problem/A
# Memory Limit: 256 MB
# Time Limit: 1000 ms

for _ in range(int(input())):
    n = int(input())
    x = 1
    if n <= 1900:
        x = 1
    elif 1600 <= n <= 1899:
        x = 2
    elif 1400 <= n <= 1599:
        x = 3
    else:
        x = 4
    print(f"Division {x}")
