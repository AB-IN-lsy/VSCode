'''
Author: NEFU AB-IN
Date: 2022-02-27 17:26:38
FilePath: \ACM\Acwing\829.py
LastEditTime: 2022-02-27 17:27:51
'''

from collections import deque

if __name__ == "__main__":
    n = int(input())
    q = deque()

    for i in range(n):
        op = input().split()
        if op[0] == "push":
            q.append(op[1])
        if op[0] == "pop":
            q.popleft()
        if op[0] == "empty":
            print("NO" if q else "YES")
        if op[0] == "query":
            print(q[0])