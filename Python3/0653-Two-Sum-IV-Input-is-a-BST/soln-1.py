class Solution:
    def findTarget(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: bool
        """
        d = set()
        def traverse(node):
            if node:
                if node.val in d:
                    return True
                d.add(k - node.val)
                return traverse(node.left) or traverse(node.right)
            return False
        return traverse(root)