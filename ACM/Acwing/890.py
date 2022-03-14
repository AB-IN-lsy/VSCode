'''
Author: NEFU AB-IN
Date: 2022-03-13 12:29:37
FilePath: \ACM\Acwing\890.py
LastEditTime: 2022-03-13 14:15:50
'''
n, m = map(int, input().split())
nums = list(map(int, input().split()))

ans = 0
for i in range(1, 1 << m):
    cnt, prob = 0, 1
    for j in range(m):
        if i >> j & 1:
            cnt += 1
            prob *= nums[j]
    if cnt & 1:
        ans += n // prob
    else:
        ans -= n // prob

print(ans)
