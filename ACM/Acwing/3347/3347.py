'''
Author: NEFU AB-IN
Date: 2022-02-18 09:41:02
FilePath: \ACM\Acwing\3347.py
LastEditTime: 2022-02-18 11:38:56
'''
from collections import Counter, deque

if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))
    res = 0
    for i in range(1, n + 1):  #枚举区间长度
        q = deque()
        d = Counter()
        cnt = 0
        for j in range(n):  #枚举区间内的数
            if len(q) < i:
                q.appendleft(a[j])
                d[a[j]] += 1
                cnt += a[j]
            if len(q) == i:
                if cnt % i == 0 and d[cnt // i]:
                    res += 1
                t = q.pop()
                d[t] -= 1
                cnt -= t
    print(res)