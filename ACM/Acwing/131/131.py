'''
Author: NEFU AB-IN
Date: 2022-02-27 09:19:29
FilePath: \ACM\Acwing\131.py
LastEditTime: 2022-02-27 09:52:36
'''

N = int(1e5 + 100)
h, l, r = [0] * N, [0] * N, [0] * N

while True:
    try:
        h = list(map(int, input().split()))[1:]
        if not h:
            break
        n = len(h)
        h = [-1, *h, -1]
        # 此次栈存的是下标，比较时换成下标比较即可
        stk = [0]
        for i in range(1, n + 1):
            while stk and h[stk[-1]] >= h[i]:
                stk.pop()
            l[i] = stk[-1] if stk else -1
            stk.append(i)

        stk = [n + 1]

        for i in range(n, -1, -1):
            while stk and h[stk[-1]] >= h[i]:
                stk.pop()
            r[i] = stk[-1] if stk else -1
            stk.append(i)

        res = 0
        for i in range(1, n + 1):
            res = max(res, h[i] * (r[i] - l[i] - 1))
        print(res)
    except:
        break