'''
Author: NEFU AB-IN
Date: 2022-03-24 19:01:54
FilePath: \ACM\Acwing\1236.2.py
LastEditTime: 2022-03-24 19:01:54
'''
N = int(1e5 + 10)
sa, sc, cnt = [0] * N, [0] * N, [0] * N

n = int(input())
INF = int(1e9)
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))

a = [i + 1 for i in a]  #下标都+1, 因为会有0，0这个位置需要空出来，所以所有数整体偏移
b = [i + 1 for i in b]
c = [i + 1 for i in c]

for i in a:
    sa[i] += 1
for i in range(1, N):
    sa[i] += sa[i - 1]
for i in range(n):
    cnt[i] = sa[b[i] - 1]

for i in c:
    sc[i] += 1
for i in range(1, N):
    sc[i] += sc[i - 1]
for i in range(n):
    cnt[i] *= (sc[N - 1] - sc[b[i]])

print(sum(cnt))
