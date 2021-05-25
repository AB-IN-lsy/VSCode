'''
Description: https://blog.csdn.net/qq_45859188
Author: NEFU AB_IN
version: 1.0
Date: 2021-01-28 23:02:48
LastEditors: NEFU AB_IN
LastEditTime: 2021-04-10 20:52:49
'''
from pythonds.basic import Queue
n = int(input())
lst = []
for _ in range(n):
    tmp = input()
    item = [int(i) for i in tmp]
    lst.append(item)
xt, yt, xg, yg = map(int, input().split())
xt -= 1
yt -= 1
xg -= 1
yg -= 1

q = Queue()

dire = [[-1, 0], [0, -1], [1, 0], [0, 1]]
q.enqueue([xt, yt, 0])
lst[xt][yt] = 1
while(q.isEmpty() == False):
    tmp = q.dequeue()
    if (tmp[0] == xg and tmp[1] == yg):
        print(tmp[2])
        break
    for i in range(4):
        x1 = tmp[0] + dire[i][0]
        y1 = tmp[1] + dire[i][1]
        if(x1 >= 0 and x1 < n and y1 >= 0 and y1 < n and lst[x1][y1] == 0):
            lst[x1][y1] = 1
            q.enqueue([x1, y1, tmp[2] + 1])



