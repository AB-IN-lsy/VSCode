'''
Author: NEFU AB-IN
Date: 2021-11-05 19:16:12
FilePath: \ACM\test.py
LastEditTime: 2021-11-25 23:39:10
'''


def solve():
    n = int(input())
    lst = list(map(int, input().split()))
    if lst[0] != max(lst) and lst[len(lst) - 1] != max(lst):
        print(-1)
        return
    if lst[0] != min(lst):
        lst.append(lst.pop(0))
    ans = [lst[0]]
    lst.pop(0)
    index = len(lst) - 1
    while lst:
        if index == len(lst) - 1 and lst[len(lst) - 1] > ans[0]:
            ans.append(lst[len(lst) - 1])
            lst.pop()
            index = 0
        elif index == 0 and lst[0] < ans[len(ans) - 1]:
            ans.insert(0, lst[0])
            lst.pop(0)
            index = len(lst) - 1
    for i in ans:
        print(i, end=" ")
    print()


for _ in range(int(input())):
    solve()