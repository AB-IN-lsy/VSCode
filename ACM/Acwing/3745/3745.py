'''
Author: NEFU AB-IN
Date: 2022-03-17 10:53:36
FilePath: \ACM\Acwing\3745.py
LastEditTime: 2022-03-17 10:53:38
'''


def check(h, p):
    ans = 0
    for i in range(n - 1, -1, -1):
        if nums[i] >= h:
            ans += 1
        else:
            if p > 0 and nums[i] + 1 >= h:
                ans += 1
                p -= 1
            else:
                break
    return ans >= h


def find():
    # 二分h
    l, r = 1, n
    while l < r:
        mid = l + r + 1 >> 1
        if check(mid, L):
            l = mid
        else:
            r = mid - 1
    return r


n, L = map(int, input().split())
nums = list(map(int, input().split()))

nums.sort()

print(find())
