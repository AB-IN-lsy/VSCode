'''
Description: https://blog.csdn.net/qq_45859188
Author: NEFU AB_IN
version: 1.0
Date: 2021-03-08 20:28:04
LastEditors: NEFU AB_IN
LastEditTime: 2021-03-10 20:29:46
'''
import math

def solve():
    n, k  = map(int, input().split())
    s = input()
    if k == 0:
        print("YES")
        return
    if n & 1:
        s1 = s[:n // 2]
        s2 = s[n // 2 + 1 :]
    else:
        s1 = s[: n // 2 - 1]
        s2 = s[n // 2 + 1: ]
    s2 = s2[::-1]
    k1 = 0
    for i in range(len(s1)):
        if s1[i] == s2[i]:
            k1 += 1
        else:
            break
    if k1 >= k:
        print("YES")
    else:
        print("NO")

for _ in range(int(input())):
    solve()