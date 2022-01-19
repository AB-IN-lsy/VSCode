'''
Author: NEFU AB-IN
Date: 2022-01-15 15:05:19
FilePath: \ACM\Acwing\1952.1.py
LastEditTime: 2022-01-16 00:25:22
'''

import bisect
import itertools

# 全局变量尽量只是定义

INF = int(2 * 1e9)
N = 20020
xs = [-INF, INF]
lst = []
b = [0] * (2 * N)


def find(x):
    l = 0
    r = len(xs) - 1
    while l < r:
        mid = l + r >> 1
        if xs[mid] >= x:
            r = mid
        else:
            l = mid + 1
    return r


# def find(x):
#     return bisect.bisect_left(xs, x)

if __name__ == '__main__':
    # xs.append(-INF)
    # xs.append(INF)
    n, x, y, z = map(int, input().split())
    for _ in range(n):
        l, r = map(int, input().split())
        lst.append((l, r))  #存原数组
        xs.append(l)  #存需离散的值
        xs.append(r + 1)

    xs = list(set(xs))  #去重并排序，这样每个 l 和 r + 1 都有一个唯一的下标对应，即数值对应下标了
    # 故xs可以说是存的对应关系
    xs.sort()
    for i in range(n):
        L = find(lst[i][0])  #找出 l 在xs中对应的下标
        R = find(lst[i][1] + 1)  #找出 r + 1 在xs中对应的下标
        # b为差分数组，此时相当于map
        b[0] += x
        b[L] += (y - x)
        b[R] -= (y - z)
        b[len(xs) - 1] -= z

    sum = 0
    res = 0
    # 从下标0开始枚举，枚举b中的值，范围就是xs的范围
    for i in range(len(xs)):
        sum += b[i]
        res = max(res, sum)
    print(res)