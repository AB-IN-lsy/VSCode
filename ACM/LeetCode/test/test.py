from typing import List


class ListNode:
    def __init__(self, val: int = 0, next_=None):
        self.val = val
        self.next = next_


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    @staticmethod
    def creatTreeNode(nums: List[int]):
        """
        输入数组层序遍历构造二叉树
        [1, 2, 3, None, 4]
            1
           / \
          2   3
           \
           4
        """
        if len(nums) == 0:
            return None
        nums_copy = nums.copy()

        popped = nums_copy.pop(0)
        root = TreeNode(popped)
        q = [root]
        while len(nums_copy) > 0:
            node = q.pop(0)

            left = nums_copy.pop(0)
            if left is not None:
                node.left = TreeNode(left)
                q.append(node.left)
            if len(nums_copy) == 0:
                break
            right = nums_copy.pop(0)
            if right is not None:
                node.right = TreeNode(right)
                q.append(node.right)
        return root

    def __str_helper(self, prefix, isTail, sb):
        if self.right is not None:
            if isTail:
                sb = self.right.__str_helper("" + prefix + "│   ", False, sb)
            else:
                sb = self.right.__str_helper("" + prefix + "    ", False, sb)

        if isTail:
            sb = sb + prefix + "└── " + str(self.val) + "\n"
        else:
            sb = sb + prefix + "┌── " + str(self.val) + "\n"

        if self.left is not None:
            if isTail:
                sb = self.left.__str_helper("" + prefix + "    ", True, sb)
            else:
                sb = self.left.__str_helper("" + prefix + "│   ", True, sb)
        return sb

    def __str__(self):
        return self.__str_helper("", True, "")


if __name__ == '__main__':
    root = TreeNode.creatTreeNode([
        1, None, 1, 1, 1, None, None, 1, 1, None, 1, None, None, None, 1, None,
        1
    ])
    print(root)