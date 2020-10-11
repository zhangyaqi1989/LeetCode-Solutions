# Definition for a binary tree node.
# class Node(object):
#     def __init__(self, val=" ", left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def checkEquivalence(self, root1: 'Node', root2: 'Node') -> bool:
        def pre_order(node, vals):
            if node is not None:
                if node.val != '+':
                    vals.append(node.val)
                pre_order(node.left, vals)
                pre_order(node.right, vals)
        vals1 = []
        vals2 = []
        pre_order(root1, vals1)
        pre_order(root2, vals2)
        vals1.sort()
        vals2.sort()
        return vals1 == vals2
