'''
Author: NEFU AB-IN
Date: 2022-03-17 21:46:46
FilePath: \ACM\Acwing\3293.py
LastEditTime: 2022-03-17 21:47:00
'''
n, k, t, xl, yd, xr, yu = map(int, input().split())

cnt1 = 0  #经过
cnt2 = 0  #逗留

for i in range(n):
    num = list(map(int, input().split()))
    cnt, flag1, flag2 = 0, 0, 0
    for j in range(0, 2 * t - 1, 2):
        x, y = num[j], num[j + 1]
        if x >= xl and x <= xr and y >= yd and y <= yu:
            cnt += 1
        else:
            cnt = 0
        if cnt >= 1:
            flag1 = 1
        if cnt >= k:
            flag2 = 1
    cnt1 += flag1
    cnt2 += flag2

print(cnt1)
print(cnt2)
