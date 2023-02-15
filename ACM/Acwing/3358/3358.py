'''
Author: NEFU AB-IN
Date: 2022-03-15 10:44:21
FilePath: \ACM\Acwing\3358.py
LastEditTime: 2022-03-15 10:44:21
'''
s = input()
s = s * 1001
start = s[0]

p = input()
j = 0
for i in range(len(p)):
    while j < len(s) and s[j] != p[i]:
        j += 1
    j += 1

print((j + 26) // 26)
