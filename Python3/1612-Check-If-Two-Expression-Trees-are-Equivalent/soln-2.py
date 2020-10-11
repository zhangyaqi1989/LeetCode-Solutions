# Definition for a binary tree node.
# class Node(object):
#     def __init__(self, val=" ", left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def checkEquivalence(self, root1: 'Node', root2: 'Node') -> bool:
        def get_leaves(node, counter):
            if node is not None:
                if node.val != '+':
                    counter[ord(node.val) - ord('a')] += 1
                get_leaves(node.left, counter)
                get_leaves(node.right, counter)
        counter1 = [0] * 26
        counter2 = [0] * 26
        get_leaves(root1, counter1)
        get_leaves(root2, counter2)
        return counter1 == counter2
