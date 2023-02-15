'''
Author: NEFU AB-IN
Date: 2022-02-27 11:29:42
FilePath: \ACM\Acwing\154.py
LastEditTime: 2022-02-27 14:55:44
'''
N = int(1e6 + 10)

q = [0] * N

if __name__ == "__main__":
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))

    hh, tt = 0, -1
    for i in range(n):
        while hh <= tt and i - k + 1 > q[hh]:
            hh += 1
        while hh <= tt and nums[q[tt]] >= nums[i]:
            tt -= 1
        tt += 1
        q[tt] = i
        if i >= k - 1:
            print(nums[q[hh]], end=" ")
    print()
    hh, tt = 0, -1
    for i in range(n):
        if hh <= tt and i - k + 1 > q[hh]:
            hh += 1
        if hh <= tt and nums[q[tt]] <= nums[i]:
            tt -= 1
        tt += 1
        q[tt] = i
        if i >= k - 1:
            print(nums[q[hh]], end=" ")
