'''
Author: NEFU AB-IN
Date: 2022-03-20 18:55:28
FilePath: \ACM\Acwing\ACC\A.PY
LastEditTime: 2022-03-20 19:17:40
'''
n = int(input())
n = hex(n)[2:]

ans1 = ['0', '4', '6', '9', 'A', 'D']
ans2 = ['8', 'B']

ans = 0
for i in str(n):
    if i.upper() in ans1:
        ans += 1
    if i.upper() in ans2:
        ans += 2

print(ans)
