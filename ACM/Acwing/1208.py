'''
Author: NEFU AB-IN
Date: 2022-03-22 19:25:51
FilePath: \ACM\Acwing\1208.py
LastEditTime: 2022-03-22 19:25:51
'''
s = list(input())
ss = list(input())


def change(i):
    if s[i] == '*':
        s[i] = 'o'
    else:
        s[i] = '*'


ans = 0
for i in range(len(s)):
    if s[i] != ss[i]:
        change(i)
        change(i + 1)
        ans += 1

print(ans)