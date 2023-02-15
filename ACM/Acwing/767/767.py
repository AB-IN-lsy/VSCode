'''
Author: NEFU AB-IN
Date: 2022-03-13 20:39:39
FilePath: \ACM\Acwing\767.py
LastEditTime: 2022-03-13 20:42:39
'''
s = list(input())

for i in range(len(s)):
    if s[i].isalpha():
        if s[i] == 'Z':
            s[i] = 'A'
        elif s[i] == 'z':
            s[i] = 'a'
        else:
            s[i] = chr(ord(s[i]) + 1)

print("".join(s))