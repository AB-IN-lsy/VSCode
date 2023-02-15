'''
Author: NEFU AB-IN
Date: 2022-05-17 13:41:43
FilePath: \ACM\Acwing\1986.py
LastEditTime: 2022-05-17 14:51:07
'''


class sa:
    def __init__(self, x, y, op):
        self.x = x
        self.y = y
        self.op = op


dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

N = 220
q = [sa(0, 0, None)]
INF = int(1e8)


def rotate(op):
    if op == '/':
        op = '\\'
    else:
        op = '/'
    return op


def check():
    k, d = 0, 1  # k代表目前是在哪， d代表目前的方向
    for _ in range(2 * (n + 1)): # 防止出现陷入环的情况
        id = -1
        minn = INF
        for i in range(1, n + 2):
            if k == i:
                continue
            # 下面四行用来判断某个镜子沿着方向向量，是否能到另一个镜子
            if q[k].x + abs(q[k].x - q[i].x) * dx[d] != q[i].x:
                continue
            if q[k].y + abs(q[k].y - q[i].y) * dy[d] != q[i].y:
                continue
            t = abs(q[k].x - q[i].x) + abs(q[k].y - q[i].y)
            if t < minn:
                minn = t
                id = i
        if id == -1: return 0
        if id == n + 1: return 1
        k = id
        if q[id].op == '/': d ^= 1  # 改变方向
        else: d ^= 3
    return 0


n, ex, ey = map(int, input().split())

for i in range(n):
    x, y, op = input().split()
    q.append(sa(int(x), int(y), op))
q.append(sa(ex, ey, None))

if check():
    print(0)
else:
    for i in range(1, n + 1):  # 枚举转哪个镜子
        q[i].op = rotate(q[i].op)
        if check():
            print(i)
            exit(0)
        q[i].op = rotate(q[i].op)
    print(-1)