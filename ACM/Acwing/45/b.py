'''
Author: NEFU AB-IN
Date: 2022-04-02 18:57:37
FilePath: \ACM\Acwing\45\b.py
LastEditTime: 2022-04-02 19:21:55
'''
N = int(1e6 + 10)
st = [0] * N

n, k = map(int, input().split())
a = list(map(int, input().split()))

j = 0
cnt = 0
ans = 0
l, r = 0, 0
for i in range(n):
    if st[a[i]] == 0:
        cnt += 1
    st[a[i]] += 1
    while j < i and cnt > k:
        st[a[j]] -= 1
        if st[a[j]] == 0: cnt -= 1
        j += 1
    if i - j + 1 > ans:
        ans = i - j + 1
        l, r = j + 1, i + 1

print(l, r)
