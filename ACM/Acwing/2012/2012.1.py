'''
Author: NEFU AB-IN
Date: 2022-05-21 16:52:41
FilePath: \ACM\Acwing\2012.1.py
LastEditTime: 2022-05-21 16:59:24
'''
N = int(1e6 + 10)
n = int(input())

st = [0] * N
a = []
for i in range(n):
    a.append(int(input()))

cnt = 0  # 记录区间内有多少个种类的数
ans = 0
# 双指针
j = 0
for i in range(n):
    if st[a[i]] == 0:
        cnt += 1
    st[a[i]] += 1

    while j < i and cnt > 2:  # 把cnt缩到2
        st[a[j]] -= 1
        if st[a[j]] == 0:
            cnt -= 1
        j += 1
    ans = max(ans, st[a[i]])

print(ans)