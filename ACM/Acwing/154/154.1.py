'''
Author: NEFU AB-IN
Date: 2022-02-27 14:47:16
FilePath: \ACM\Acwing\154.1.py
LastEditTime: 2022-02-27 15:07:42
'''
from collections import deque

N = int(1e6 + 10)
q = deque()

if __name__ == "__main__":
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    for i in range(n):
        while q and i - q[0] + 1 > k:
            q.popleft()
        while q and nums[q[-1]] >= nums[i]:
            q.pop()
        q.append(i)
        if i >= k - 1:
            print(nums[q[0]], end=" ")

    q.clear()
    print()

    for i in range(n):
        while q and i - q[0] + 1 > k:
            q.popleft()
        while q and nums[q[-1]] <= nums[i]:
            q.pop()
        q.append(i)
        if i >= k - 1:
            print(nums[q[0]], end=" ")
