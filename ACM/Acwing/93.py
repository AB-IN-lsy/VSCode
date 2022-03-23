'''
Author: NEFU AB-IN
Date: 2022-03-21 20:58:30
FilePath: \ACM\Acwing\93.py
LastEditTime: 2022-03-21 20:58:30
'''
n, m = map(int, input().split())

res = []
for i in range(1 << n):
    ans = []
    for j in range(n):
        if i & 1 << j:
            ans.append(j + 1)
    if len(ans) == m:
        res.append(ans)

res.sort()

for num in res:
    for i in num:
        print(i, end=" ")
    print()