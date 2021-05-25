'''
Description: file content
Author: NEFU AB_IN
version: 1.0
Date: 2021-05-21 13:09:13
LastEditors: NEFU AB_IN
LastEditTime: 2021-05-22 10:55:54
'''
class minheap:
    def __init__(self):
        self.data = []
    
    def __len__(self):
        return len(self.data)
    
    def __repr__(self):
        lst = [str(i) for i in self.data]
        return ", ".join(lst)
    
    def sink(self, lst, i, n):
        l = 2 * i + 1
        r = 2 * i + 2
        pos = i
        if l < n and lst[l] < lst[pos]:
            pos = l
        if r < n and lst[r] < lst[pos]:
            pos = r
        if pos != i:
            lst[pos], lst[i] = lst[i], lst[pos]
            self.sink(lst, pos, n)

    def build(self, lst):
        for i in range((len(lst) - 2) // 2, -1, -1):
            self.sink(lst, i, len(lst))
        self.data = lst
    
    def insert(self, x):
        self.data.append(x)
        k = len(self) - 1
        while k > 0:
            if self.data[k] < self.data[k // 2]: # 小根堆用小于号
                self.data[k], self.data[k // 2] = self.data[k // 2], self.data[k]
                k = k // 2
            else:
                return
        
    def delete_min(self):
        if len(self) == 0:
            print("The heap is empty!")
            return
        self.data[0], self.data[len(self) - 1] = self.data[len(self) - 1], self.data[0]
        self.sink(self.data, 0, len(self) - 1)
        return self.data.pop()

h = minheap()
h.build([7, 5, 1, 3, 6])
print(h)
h.delete_min()
print(h)
h.delete_min()
print(h)
h.insert(2)
print(h)
        
    