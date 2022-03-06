'''
Author: NEFU AB-IN
Date: 2022-03-05 18:59:48
FilePath: \ACM\Acwing\41周赛\a.py
LastEditTime: 2022-03-05 19:03:50
'''
s1, s2 = input().split()

res = s1[0]
for i in range(1, len(s1)):
    if s1[i] > s2[0]:
        res += s2[0]
        print(res)
        exit(0)
    res += s1[i]
if res == s1:
    res += s2[0]
print(res)