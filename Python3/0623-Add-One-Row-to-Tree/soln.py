# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def addOneRow(self, root, v, d):
        """
        :type root: TreeNode
        :type v: int
        :type d: int
        :rtype: TreeNode
        """
        # level order traversal
        if d == 1:
            node = TreeNode(v)
            node.left = root
            return node
        nodes = [root]
        d -= 1
        while d > 1:
            temp = []
            for node in nodes:
                if node.left:
                    temp.append(node.left)
                if node.right:
                    temp.append(node.right)
            nodes = temp
            d -= 1
        for node in nodes:
            left, right = node.left, node.right
            node.left = TreeNode(v)
            node.right = TreeNode(v)
            node.left.left = left
            node.right.right = right
        return root