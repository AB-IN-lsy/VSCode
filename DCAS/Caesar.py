'''
Author: NEFU AB-IN
Date: 2021-12-01 20:53:21
FilePath: \DCAS\caesar.py
LastEditTime: 2021-12-01 21:17:33
'''
s = input()
for i in range(0, 26):
    ss = list()
    for j in s:
        if j.isalpha() and j.islower():
            xx = (((ord(j) + i) - ord('a')) % 26) + ord('a')
            ss.append(chr(xx))
        elif j.isalpha() and j.isupper():
            xx = (((ord(j) + i) - ord('A')) % 26) + ord('A')
            ss.append(chr(xx))
        else:
            ss.append(j)
    print(f'key = {str(i)} : {"".join(ss)}')
