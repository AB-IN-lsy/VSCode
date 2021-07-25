'''
Description: file content
Author: NEFU AB_IN
version: 1.0
Date: 2021-05-28 09:17:37
LastEditors: NEFU AB_IN
LastEditTime: 2021-05-28 22:23:58
'''
class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right
    
    def __repr__(self):
        return str(self.data)

class BST:
    def __init__(self, root=None):
        self.root = root

    def insert(self, key):
        self.root = self.__insert_rec(self.root, key)

    def __insert_rec(self, root, key):
        if root is None:
            return Node(key)
        else:
            if key < root.data:
                root.left = self.__insert_rec(root.left, key)
            else:
                root.right = self.__insert_rec(root.right, key)
        return root

    def search(self, key):
        cur_node = self.root
        while cur_node:
            if key < cur_node.data:
                cur_node = cur_node.left
            elif key > cur_node.data:
                cur_node = cur_node.right
            else:
                return True
        return False

def LCA(bst, x, y):
    if bst.root is None or not bst.search(x) or not bst.search(y):
        return None
 
    cur_node = bst.root
 
    while cur_node:
        if cur_node.data > max(x, y):
            cur_node = cur_node.left
        elif cur_node.data < min(x, y):
            cur_node = cur_node.right
        else:
            return cur_node
 
    return cur_node