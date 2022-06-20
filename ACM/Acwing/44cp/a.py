'''
Author: NEFU AB-IN
Date: 2022-03-26 18:53:57
FilePath: \ACM\Acwing\44\a.py
LastEditTime: 2022-03-26 19:01:13
'''
n = int(input())
s = set()
a = list(map(int, input().split()))

for i in a:
    if i > 0: s.add(i)
print(len(s))