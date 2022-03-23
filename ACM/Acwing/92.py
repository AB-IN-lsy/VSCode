'''
Author: NEFU AB-IN
Date: 2022-03-21 14:20:16
FilePath: \ACM\Acwing\92.py
LastEditTime: 2022-03-21 15:02:20
'''
n = int(input())
a = [i for i in range(1, n + 1)]

for i in range(1 << n):
    for j in range(n):
        if i & 1 << j:
            print(a[j], end=" ")
    print()
