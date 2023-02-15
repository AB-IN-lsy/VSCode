'''
Author: NEFU AB-IN
Date: 2022-04-14 22:28:56
FilePath: \ACM\Acwing\1883.py
LastEditTime: 2022-04-18 20:39:11
'''
s = input()
t = input()

stk = []
for i in range(len(s)):
    stk.append(s[i])
    if len(stk) >= len(t) and "".join(stk[-len(t):]) == t:
        for i in range(len(t)):
            stk.pop()

print("".join(stk))