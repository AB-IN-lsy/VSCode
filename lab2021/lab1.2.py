'''
Description: https://blog.csdn.net/qq_45859188
Author: NEFU AB_IN
version: 1.0
Date: 2021-05-07 08:41:28
LastEditors: NEFU AB_IN
LastEditTime: 2021-05-07 09:09:07
'''
class StackNode:
    def __init__(self, data, nxt):
        self.data = data
        self.nxt = nxt
        


class TestBM:
    def BracketMatch(self, str1):
        head_zuo = None
        head_you = None
        d = {"{" : "}", "(" : ")", "[" : "]"}
        for i in str1:
            if i not in d.keys() and i not in d.values():
                continue
            if i in d.keys():
                head_zuo = StackNode(i, head_zuo)
            else:
                if d[head_zuo.data] == i:
                    head_zuo = head_zuo.nxt
                else:
                    head_you = StackNode(i, head_you)
        while head_you != None:
            if head_you.data == d[head_zuo.data]:
                head_you = head_you.nxt
                head_zuo = head_zuo.nxt
            else:
                break
        if head_you == None and head_zuo == None:
            print("Ture")
        else:
            print("False")

TBM = TestBM()
TBM. BracketMatch("{ } { {( }} ) ")
