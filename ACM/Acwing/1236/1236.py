'''
Author: NEFU AB-IN
Date: 2022-03-24 16:34:59
FilePath: \ACM\Acwing\1236.py
LastEditTime: 2022-03-24 17:13:11
'''
n = int(input())

a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))

a.sort()
b.sort()
c.sort()
ans = 0
for i in range(n):
    l, r = 0, n
    while l < r:
        mid = l + r >> 1
        if a[mid] >= b[i]:
            r = mid
        else:
            l = mid + 1
    tmp1 = r

    l, r = -1, n - 1
    while l < r:
        mid = l + r + 1 >> 1
        if c[mid] <= b[i]:
            l = mid
        else:
            r = mid - 1

    tmp2 = n - (r + 1)
    # print(tmp1, tmp2)
    ans += tmp1 * tmp2

print(ans)