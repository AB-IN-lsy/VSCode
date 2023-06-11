'''
Author: NEFU AB-IN
Date: 2022-04-07 21:01:05
FilePath: \ACM\LanQiao\1021.py
LastEditTime: 2022-04-07 21:01:06
'''
import os
import sys

# 请在此输入您的代码
a = input()
ans = [1] * len(a)
for i in range(len(a)):
    for z in range(i):
        if a[z] < a[i]:
            ans[i] += ans[z]
        elif a[z] == a[i]:
            ans[i] -= ans[z]

print(sum(ans))