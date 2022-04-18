'''
Author: NEFU AB-IN
Date: 2022-04-03 14:48:24
FilePath: \ACM\ACnowcoder\2022.4.3\e.py
LastEditTime: 2022-04-03 14:51:48
'''
from string import ascii_lowercase


def judge(l, r):
    for i in ascii_lowercase:
        if i != l and i != r:
            return i


for _ in range(int(input())):
    s = list("#" + input() + "#")
    for i in range(1, len(s) - 1):
        if s[i] == '?':
            s[i] = judge(s[i - 1], s[i + 1])
    print("".join(s[1:len(s) - 1]))