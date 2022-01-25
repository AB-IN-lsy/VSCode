'''
Author: NEFU AB-IN
Date: 2022-01-22 19:50:29
FilePath: \ACM\Acwing\1904.py
LastEditTime: 2022-01-22 21:02:32
'''
'''
最终追尾成一个点的牛，必然是一个连续的段
求区间数 = 求每个区间的队长数（最右边的牛） = 判断每个牛是不是队长 = 判断这个牛会不会$不追尾$右边的牛 = 判断这个牛的速度是不是小于等于右边速度的最小值
'''

lst = []
INF = int(2e9)

if __name__ == "__main__":
    n = int(input())

    for _ in range(n):
        x, v = map(int, input().split())
        lst.append(v)
    vmin = INF
    res = 0
    for i in range(n - 1, -1, -1):
        if lst[i] <= vmin:
            res += 1
            vmin = lst[i]
    print(res)
