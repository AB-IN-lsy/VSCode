'''
Description: 
Author: NEFU AB_IN
version: 1.0
Date: 2021-02-16 17:07:34
LastEditors: NEFU AB_IN
LastEditTime: 2021-03-05 18:38:16
'''
s = list(input())
l = list(input())
lst = [s[0]]
l = ["0"] + l
ind = 0
for i in range(len(l) - 1):
    if l[i] == "L":
        lst.insert(ind, s[i])
    if l[i] == "R":
        ind += 1
        lst.insert(ind, s[i])
print("".join(lst))