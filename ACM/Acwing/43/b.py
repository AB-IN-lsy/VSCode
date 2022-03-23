'''
Author: NEFU AB-IN
Date: 2022-03-19 18:54:01
FilePath: \ACM\Acwing\43\b.py
LastEditTime: 2022-03-20 10:44:03
'''
n, s = map(int, input().split())

a = list(map(int, input().split()))
sum = sum(a)


def get(l1, r1, l2, r2):
    return min(r1, r2) - max(l1, l2) + 1


for i in range(n):
    l1, r1 = 1, a[i]
    l2 = s - (sum - a[i])
    r2 = s - (n - 1)

    ans = get(l1, r1, l2, r2)
    print(a[i] - ans, end=" ")
