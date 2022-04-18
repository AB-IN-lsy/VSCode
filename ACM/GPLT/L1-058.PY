'''
Author: NEFU AB-IN
Date: 2022-04-16 21:45:20
FilePath: \ACM\GPLT\L1-058.PY
LastEditTime: 2022-04-16 21:49:01
'''
s = list(input())
i = 0
while i < len(s):
    if s[i] != '6':
        i += 1
        continue
    j = i
    while j < len(s) and s[j] == '6':
        j += 1
    if j - i + 1 > 9:
        s[i:j] = ['27']
    elif j - i + 1 > 3:
        s[i:j] = ['9']
    i += 1
print("".join(s))