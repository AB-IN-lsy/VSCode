'''
Author: NEFU AB-IN
Date: 2022-04-08 21:36:35
FilePath: \ACM\ACnowcoder\2022.4.8\d.py
LastEditTime: 2022-04-08 21:36:36
'''


def ord1(x):
    return ord(x) - ord('a')


N = int(2e5 + 10)
for _ in range(int(input())):
    n = int(input())
    dp = [0] * N
    for i in range(n):
        s = input()
        dp[ord1(s[-1])] = max(dp[ord1(s[-1])], dp[ord1(s[0])] + len(s))
    ans = 0
    for i in range(26):
        ans = max(ans, dp[i])
    print(ans)
