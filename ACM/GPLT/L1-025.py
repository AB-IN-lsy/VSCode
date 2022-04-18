'''
Author: NEFU AB-IN
Date: 2022-04-15 15:46:09
FilePath: \ACM\GPLT\L1-025.py
LastEditTime: 2022-04-15 15:46:10
'''


def judge(x):
    if x.isdigit() and 1 <= int(x) <= 1000:
        return 1
    return 0


s = input().split()

a, b = "?", "?"

if len(s) == 2:
    if judge(s[0]): a = int(s[0])
    if judge(s[1]): b = int(s[1])
else:
    if judge(s[0]): a = int(s[0])
flag = 0
if a == "?" or b == "?":
    flag = 1

if flag:
    ans = "?"
else:
    ans = a + b
print(f"{a} + {b} = {ans}")