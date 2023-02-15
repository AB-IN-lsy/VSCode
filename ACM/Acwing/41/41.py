'''
Author: NEFU AB-IN
Date: 2022-02-27 17:52:22
FilePath: \ACM\Acwing\41.py
LastEditTime: 2022-02-27 17:53:35
'''


class MinStack(object):
    def __init__(self):
        self.a = []
        self.b = []
        """
        initialize your data structure here.
        """

    def push(self, x):
        self.a.append(x)
        if not self.b:
            self.b.append(x)
        else:
            self.b.append(min(self.b[-1], x))
        """
        :type x: int
        :rtype: void
        """

    def pop(self):
        self.a.pop()
        self.b.pop()
        """
        :rtype: void
        """

    def top(self):
        return self.a[-1]
        """
        :rtype: int
        """

    def getMin(self):
        return self.b[-1]
        """
        :rtype: int
        """


# Your MinStack object will be instantiated and called as such:
obj = MinStack()
obj.push(1)
obj.push(2)
obj.push(-1)

obj.pop()
param_3 = obj.top()
param_4 = obj.getMin()