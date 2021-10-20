'''
Author: NEFU AB-IN
Date: 2021-10-08 20:37:06
FilePath: \ACM\CF\2021.10.8\b..py
LastEditTime: 2021-10-08 20:49:02
'''
s = list(input())
t = list(input())
if s == t:
    print("Yes")
    exit(0)
for i in range(len(s) - 1):
    ts = s.copy()
    tt = ts[i]
    ts[i] = ts[i + 1]
    ts[i + 1] = tt
    if t == ts:
        print("Yes")
        exit(0)
print("No")
