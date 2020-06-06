class Solution:
    def printTree(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[str]]
        """
        def depth(node):
            if node is None:
                return 0
            return 1 + max(depth(node.left), depth(node.right))
        d = depth(root)
        width = 2 ** d - 1
        ans = [[''] * width for _ in range(d)]
        def helper(node, r, c, w):
            if node is not None:
                ans[r][c] = str(node.val)
                if node.left is not None:
                    helper(node.left, r + 1, c - (w + 1)//2, w//2)
                if node.right is not None:
                    helper(node.right, r + 1, c + (w + 1)//2, w//2)
        helper(root, 0, width//2, width//2)
        return ans
