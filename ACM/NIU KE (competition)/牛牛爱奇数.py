#
# 返回一个数，代表让这些数都变成奇数的最少的操作次数
# @param n int整型 代表一共有多少数
# @param a int整型一维数组 代表n个数字的值
# @return int整型
#
class Solution:
    def solve(self , n , a ):
        s = set()
        for i in range(n):
            while a[i]%2==0:
                s.add(a[i])
                a[i] = a[i]//2
        return len(s)
n=int(input())
a=list(map(int ,input().split()))
print(Solution().solve(n,a))