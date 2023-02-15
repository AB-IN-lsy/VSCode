'''
Author: NEFU AB-IN
Date: 2022-03-18 14:44:32
FilePath: \ACM\Acwing\3290.py
LastEditTime: 2022-03-18 14:44:32
'''
n, m = map(int, input().split())

A = []
B = []

for i in range(n):
    x, y, f = input().split()
    x, y = map(int, [x, y])
    if f == "A":
        A.append([x, y])
    else:
        B.append([x, y])

for i in range(m):
    a1, a2, a3 = map(int, input().split())
    flag1_a, flag2_a, flag1_b, flag2_b = [0] * 4
    for x, y in A:
        if a1 + a2 * x + a3 * y >= 0:
            flag1_a = 1
        else:
            flag1_b = 1
    for x, y in B:
        if a1 + a2 * x + a3 * y >= 0:
            flag2_a = 1
        else:
            flag2_b = 1
    if flag1_a + flag1_b == 2 or flag2_a + flag2_b == 2:
        print("No")
        continue
    if (flag1_a and flag2_b) or (flag1_b and flag2_a):
        print("Yes")
        continue
    print("No")
