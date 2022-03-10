'''
Author: NEFU AB-IN
Date: 2022-03-08 18:42:37
FilePath: \ACM\Acwing\1081.py
LastEditTime: 2022-03-09 11:12:07
'''
N = 35
dp = [[0] * N for _ in range(N)]


def init():
    for i in range(N):
        for j in range(i + 1):
            if j == 0:
                dp[i][j] = 1
            else:
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]


def f(x):
    if x == 0:
        return 0
    v = []
    while x:
        v.append(x % b)
        x //= b
    res, last = 0, 0  #last 表示已经选了多少个1
    for i in range(len(v) - 1, -1, -1):
        x = v[i]  #枚举B进制的每一位
        if x:  # 枚举左子树，如果x>0，才可能有左子树
            res += dp[i][k - last]  #加上C(i, k - last)
            if x > 1:  #还是在左子树，如果x>1，先加上这个位置选1的情况
                if k - last - 1 >= 0:
                    res += dp[i][k - last - 1]
                break  #再看右子树，是这个位置只能选x，但x>1，我们只能选01，所以不存在右子树，直接break
            else:
                last += 1  #如果x=1，那么就是这个位置选1了，看左子树，只能选0，所以左子树不存在选1的情况，故res不加
                if last > k:
                    break
        if i == 0 and last == k:  #最后一定加上last == k，判断之前的是否合法
            res += 1
    return res


init()
x, y = map(int, input().split())
k = int(input())
b = int(input())

print(f(y) - f(x - 1))