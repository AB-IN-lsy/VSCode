'''
Author: NEFU AB-IN
Date: 2022-03-13 16:54:54
FilePath: \ACM\Acwing\291.py
LastEditTime: 2022-03-13 17:17:23
'''
N = 13  #列
M = 1 << N  #列的可能的种类
dp = [[0] * M for _ in range(N)]
st = [0] * M
state = [[] for _ in range(M)]

while True:
    try:
        n, m = map(int, input().split())
        if n == 0 and m == 0:
            break
        for i in range(1 << n):  #预处理每一列的合法情况
            cnt = 0
            flag = 1
            for j in range(n):
                if i >> j & 1:
                    if cnt & 1:
                        flag = 0
                        break
                else:
                    cnt += 1
            if cnt & 1:
                flag = 0
            st[i] = flag

        for j in range(1 << n):
            state[j] = []
            for k in range(1 << n):
                if j & k == 0 and st[j | k]:  # 保证j,k不起冲突，也要保证k突进来的，对j没有影响
                    state[j].append(k)

        dp = [[0] * M for _ in range(N)]
        dp[0][0] = 1

        for i in range(1, m + 1):
            for j in range(1 << n):
                for k in state[j]:
                    dp[i][j] += dp[i - 1][k]

        print(dp[m][0])
    except:
        break