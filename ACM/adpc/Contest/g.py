'''
Author: NEFU AB-IN
Date: 2022-03-27 09:24:26
FilePath: \ACM\Contest\g.py
LastEditTime: 2022-03-27 09:26:22
'''
s = ".mp4"
n = int(input())
ans = []
for i in range(1, n + 1):
    ss = "".join([str(i), s])
    ans.append(ss)

ans.sort()

for i in range(50):
    print(ans[i])
