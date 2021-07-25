'''
Description: https://blog.csdn.net/qq_45859188
Author: NEFU AB_IN
version: 1.0
Date: 2021-05-14 08:18:18
LastEditors: NEFU AB_IN
LastEditTime: 2021-05-14 09:53:59
'''
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
    def __repr__(self):
        return str(self.data)

class LinkedList:
    def __init__(self, a=None):
        self.head = Node(None) # a dummy head node
        if a:
            for data in a:
                self.insert(data, pos=len(self)) # append nodes to the end

    def __len__(self):
        cur_node = self.head
        count = 0
        while cur_node:
            cur_node = cur_node.next
            count += 1
        return count

    def __repr__(self):
        rep = ''
        cur_node = self.head
        while cur_node.data != None:
            rep += str(cur_node) + ', '
            cur_node = cur_node.next
        if len(rep) > 0:
            rep = rep[:-2]
        return '[' + rep + ']'
    
    def insert(self, data, pos=0): # insert data at position pos
        new_node = Node(data)
        tmp = pre = self.head
        cnt = 0
        if tmp == None:
            return
        while tmp.next:
            if cnt == pos:
                break
            pre = tmp
            tmp = tmp.next
            cnt += 1
        if pre == tmp:
            new_node.next = tmp
            self.head = new_node
            return
        pre.next = new_node
        new_node.next = tmp
        
    def delete(self, pos): # delete the node at position pos
        tmp = pre = self.head
        cnt = 0
        while tmp.next:
            if cnt == pos:
                break
            pre = tmp
            tmp = tmp.next
            cnt += 1
        if pre == tmp:
            self.head = self.head.next
            return
        pre.next = tmp.next

        
def insert_sort_linkedlist(a):
    tmp = a.head
    tmp = tmp.next
    pos_node = 1
    if tmp == None or tmp.next == None:
        return
    while tmp.next:
        data = tmp.data
        pre = a.head
        pos = 0
        while pre.next:
            if data > pre.data:
                pos += 1
            else:
                break
            pre = pre.next
        a.delete(pos_node)
        a.insert(data, pos)
        tmp = tmp.next
        pos_node += 1
        print(a)

a = LinkedList([100])
insert_sort_linkedlist(a)
