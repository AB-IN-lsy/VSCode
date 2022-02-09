'''
Author: NEFU AB-IN
Date: 2022-02-09 09:44:52
FilePath: \ACM\Acwing\803.py
LastEditTime: 2022-02-09 09:47:55
'''

a = []
INF = int(2e9)

if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        a.append(list(map(int, input().split())))
    a.sort()
    res = 0

    st, ed = -INF, -INF
    for i in range(n):
        if ed < a[i][0]:
            if st != -INF and ed != -INF:
                res += 1
            st = a[i][0]
            ed = a[i][1]
        else:
            ed = max(ed, a[i][1])
    if st != -INF and ed != -INF:
        res += 1
    print(res)
