'''
Description: https://blog.csdn.net/qq_45859188
Author: NEFU AB_IN
version: 1.0
Date: 2021-05-07 09:10:21
LastEditors: NEFU AB_IN
LastEditTime: 2021-05-08 17:10:19
'''
class QueueNode():
    def __init__(self, data, nxt):
        self.data = data
        self.nxt = nxt

class LinkQueue():
    def __init__(self):
        tQueueNode = None
        self.front = tQueueNode
        self.rear = tQueueNode
    def enqueue(self, data):
        tmp = QueueNode(data, None)
        if self.front == None:
            self.front = tmp
            self.rear = tmp
            self.front.nxt = self.rear
        else:
            self.rear.nxt = tmp
            self.rear = tmp
            self.rear.nxt = self.front
    def dequeue(self):
        top = self.front.data
        if self.front == self.rear:
            self.front = self.rear = None
        else:
            self.front = self.front.nxt
            self.rear.nxt = self.front
        return top

class TestJP():
    def Josephus(self, n, k):
        queue = LinkQueue()
        for i in range(1, n + 1):
            queue.enqueue(i)
        pre = temp = queue.front
        while temp.nxt != temp:
            cnt = 1
            while cnt <= k - 1:
                pre = temp
                temp = temp.nxt
                cnt += 1
            print(temp.data, end = " ")
            pre.nxt = temp.nxt
            temp = pre.nxt
        print(temp.data)

TJP = TestJP()
TJP.Josephus(7,3)
