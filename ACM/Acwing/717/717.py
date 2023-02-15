'''
Author: NEFU AB-IN
Date: 2022-03-21 18:02:02
FilePath: \ACM\Acwing\717.py
LastEditTime: 2022-03-21 18:02:02
'''
n = int(input())
a = [0, 0, 1]

for i in range(3, n + 1):
    a.append(a[i - 1] + a[i - 2])
    if i == n:
        break

print(" ".join(map(str, a[1:n + 1])))
