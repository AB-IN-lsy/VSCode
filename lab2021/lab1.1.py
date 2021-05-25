'''
Description: https://blog.csdn.net/qq_45859188
Author: NEFU AB_IN
version: 1.0
Date: 2021-03-14 09:56:33
LastEditors: NEFU AB_IN
LastEditTime: 2021-05-07 08:38:42
'''
class Node:
    def __init__(self, data, nxt):
        self.data = data
        self.next = nxt
class Linked_List:
    def __init__(self):
        self.head = None
    def initlist(self,data_list):
        for i in data_list:
            self.head = Node(i, self.head)
    def reverse(self):
        #no code here
        a = 1
    def print_list(self):
        print("linked_list:")
        tmp = self.head
        lst = []
        while tmp != None:
            lst.append(tmp.data)
            tmp = tmp.next