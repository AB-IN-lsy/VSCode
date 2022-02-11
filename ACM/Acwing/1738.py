'''
Author: NEFU AB-IN
Date: 2022-02-10 09:29:20
FilePath: \ACM\Acwing\1738.py
LastEditTime: 2022-02-10 10:14:41
'''
N = 110
p = [0 for _ in range(N)]  #表示第i个点下一个走的点的坐标为p[i]
deg = [0 for _ in range(N)]  #入度
INF = int(2e9)

if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))
    if n <= 2:
        print(1)
        exit(0)
    a.sort()
    a = [-INF] + a + [INF]
    for i in range(1, n + 1):
        if a[i] - a[i - 1] <= a[i + 1] - a[i]:
            p[i] = i - 1
            deg[i - 1] += 1
        else:
            p[i] = i + 1
            deg[i + 1] += 1
    res = 0
    for i in range(1, n + 1):
        if not deg[i]:
            res += 2
        elif p[p[i]] == i and deg[i] == 1 and deg[p[i]] == 1:
            res += 1
    print(res // 2)