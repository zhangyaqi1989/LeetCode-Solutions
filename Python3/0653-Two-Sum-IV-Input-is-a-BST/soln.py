class Solution:
    def findTarget(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: bool
        """
        if not root:
            return False
        seen = set()
        stack = [root]
        for node in stack:
            if k - node.val in seen:
                return True
            seen.add(node.val)
            if node.left: stack.append(node.left)
            if node.right: stack.append(node.right)
        return False