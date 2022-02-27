'''
Author: NEFU AB-IN
Date: 2022-02-26 20:13:53
FilePath: \ACM\Acwing\830.py
LastEditTime: 2022-02-27 09:14:49
'''

if __name__ == "__main__":
    n = int(input())
    nums = list(map(int, input().split()))
    stk = []
    for num in nums:
        while stk and stk[-1] >= num:
            stk.pop()
        print(stk[-1] if stk else -1, end=" ")
        stk.append(num)
