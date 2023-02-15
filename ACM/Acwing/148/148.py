'''
Author: NEFU AB-IN
Date: 2022-03-15 15:50:29
FilePath: \ACM\Acwing\148.py
LastEditTime: 2022-03-15 15:50:29
'''
from heapq import heappush, heappop

n = int(input())
q = []
nums = map(int, input().split())

for num in nums:
    heappush(q, num)

ans = 0
while len(q) > 1:
    a = heappop(q)
    b = heappop(q)
    ans += (a + b)
    heappush(q, a + b)
print(ans)