'''
Description: file content
Author: NEFU AB_IN
version: 1.0
Date: 2021-05-28 08:10:27
LastEditors: NEFU AB_IN
LastEditTime: 2021-05-28 09:13:26
'''

cnt = 0
def inorder(index, lst, l):
    global cnt
    if index > len(lst):
        return
    inorder(index << 1, lst, l)
    l[index] = lst[cnt]
    cnt += 1
    inorder(index << 1 | 1, lst, l)

     

def to_bst(lst):
    lst.sort()
    l = [0 for i in range(len(lst) + 1)]
    inorder(1, lst, l)
    l.pop(0)
    for i in range(len(lst)):
        lst[i] = l[i]


keys = [29, 72, 1, 34, 22]
to_bst(keys)
print(keys)