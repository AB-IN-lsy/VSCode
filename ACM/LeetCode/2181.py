'''
Author: NEFU AB-IN
Date: 2022-02-22 09:19:30
FilePath: \ACM\LeetCode\2181.py
LastEditTime: 2022-02-22 11:38:47
'''

from operator import ne


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeNodes(self, head: ListNode) -> ListNode:
        pre, cur = head, head.next
        cnt = 0
        while cur:
            cnt += cur.val
            if cur.val == 0:
                pre.val = cnt
                pre.next = None if cur.next == None else cur
                pre = pre.next
                cnt = 0
            cur = cur.next
        return head


print(Solution().mergeNodes(
    ListNode(
        0,
        ListNode(
            3,
            ListNode(1, ListNode(0, ListNode(4, ListNode(5,
                                                         ListNode(0,
                                                                  None)))))))))
