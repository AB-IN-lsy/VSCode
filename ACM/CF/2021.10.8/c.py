'''
Author: NEFU AB-IN
Date: 2021-10-08 20:58:12
FilePath: \ACM\CF\2021.10.8\c.py
LastEditTime: 2021-10-08 21:00:59
'''
s = list(input())
x = y = 0
s.sort(reverse=True)
for i in range(len(s)):
    if x > y:
        y = y * 10 + int(s[i])
    else:
        x = x * 10 + int(s[i])
print(x * y)
