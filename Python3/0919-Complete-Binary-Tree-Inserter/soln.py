# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# think about the implement of priority tree
class CBTInserter:

    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.tree = [root] if root else []
        for node in self.tree:
            if node.left: self.tree.append(node.left)
            if node.right: self.tree.append(node.right)
        

    def insert(self, v):
        """
        :type v: int
        :rtype: int
        """
        # [0, 1, 2, 3]
        #     1
        #  2    3
        # 4 5  6 7
        node = TreeNode(v)
        N = len(self.tree)
        self.tree.append(node)
        if N % 2 == 0:
            self.tree[(N - 1) // 2].right = self.tree[-1]
        else:
            self.tree[(N - 1) // 2].left = self.tree[-1]
        return self.tree[(N - 1) // 2].val
        

    def get_root(self):
        """
        :rtype: TreeNode
        """
        return self.tree[0]
        


# Your CBTInserter object will be instantiated and called as such:
# obj = CBTInserter(root)
# param_1 = obj.insert(v)
# param_2 = obj.get_root()