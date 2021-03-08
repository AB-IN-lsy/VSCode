'''
Description: 
Author: NEFU AB_IN
version: 1.0
Date: 2021-02-16 15:40:16
LastEditors: NEFU AB_IN
LastEditTime: 2021-03-06 23:46:36
'''
def gg(x):
    if x == "0":
        return "0"
    elif x == "1":
        return "1"
    elif x == "2":
        return "5"
    elif x == "5":
        return "2"
    elif x == "8":
        return "8"
    else:
        return "-"

def solve():
    h, m = map(int, input().split())
    s, f = map(int, input().split(":"))
    for i in range(s, h):
        for j in range(f, m):
            if i != s:
                j = 0
            ss = ""
            ff = ""
            ii = str(i)
            jj = str(j)
            if len(ii) == 1:
                ii = "0" + ii
            if len(jj) == 1:
                jj = "0" + jj
            for c in ii:
                ss += gg(c)
            for c in jj:
                ff += gg(c)
            if ss.count("-") == 0 and ff.count("-") == 0 and int(ss[::-1]) <= m - 1 and int(ff[::-1]) <= h - 1:
                print(f'{ii}:{jj}')
                return
    print("00:00")

import math
for _ in range(int(input())):
    solve()