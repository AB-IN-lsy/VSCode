'''
Author: NEFU AB-IN
Date: 2022-04-07 18:41:50
FilePath: \ACM\Acwing\2066.py
LastEditTime: 2022-04-07 18:46:09
'''
s = input()
ss = ""

for i in range(len(s)):
    if s[i].isdigit() and i > 0:
        ss += s[i - 1] * (int(s[i]) - 1)
    else:
        ss += s[i]

print(ss)