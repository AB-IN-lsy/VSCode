'''
Author: NEFU AB-IN
Date: 2022-04-16 19:38:19
FilePath: \ACM\Acwing\47\c.py
LastEditTime: 2022-04-16 19:38:20
'''
n = int(input())
a = [0, *list(map(int, input().split()))]

b = [0] * 1100
for i in range(1, n + 1):
    b[i] = a[i] - a[i - 1]
ans = []
for k in range(1, n + 1):
    flag = 0
    for i in range(1, n + 1):
        if i + k > n:
            break
        if b[i] != b[i + k]:
            flag = 1
            break
    if flag == 0:
        ans.append(k)
print(len(ans))
for i in ans:
    print(i, end=" ")
