class Solution:
    def widthOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        nodes = [(root, 0)]
        ans = 1
        while nodes:
            temp, left, right = [], None, None
            for node, col in nodes:
                if node.left:
                    temp.append((node.left, 2 * col))
                    if left is None:
                        left = right = 2 * col
                    else:
                        right = 2 * col
                if node.right:
                    temp.append((node.right, 2 * col + 1))
                    if left is None:
                        left = right = 2 * col + 1
                    else:
                        right = 2 * col + 1
            if left is not None:
                ans = max(ans, right - left + 1)
            nodes = temp
        return ans