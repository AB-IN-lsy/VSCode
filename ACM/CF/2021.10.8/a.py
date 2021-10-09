'''
Author: NEFU AB-IN
Date: 2021-10-08 20:29:26
FilePath: \ACM\CF\2021.10.8\a.py
LastEditTime: 2021-10-08 20:30:21
'''
n, m = map(int, input().split())
ans = 1
for i in range(n - m):
    ans *= 32
print(ans)