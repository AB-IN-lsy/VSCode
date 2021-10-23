'''
Description: file content
Author: NEFU AB_IN
version: 1.0
Date: 2021-08-07 12:10:10
LastEditors: NEFU AB_IN
LastEditTime: 2021-08-07 12:55:37
'''
x, s = list(map(int, input().split()))
x = bin(x)[2:][::-1]
s = bin(s)[2:][::-1]

if len(x) > len(s):
    print(0)
    exit(0)
ans = 1
for i in range(len(x)):
    if x[i] == '1' and s[i] == '0':
        ans = 0
        break
    if x[i] == '1' and s[i] == '1':
        ans *= 2
print(x, s)
print(ans)
