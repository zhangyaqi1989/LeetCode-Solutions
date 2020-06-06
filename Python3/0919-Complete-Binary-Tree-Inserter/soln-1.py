# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class CBTInserter:

    def __init__(self, root):
        """
        :type root: TreeNode
        """
        # put it in an array
        self.tree = [root] if root else []
        for node in self.tree:
            self.tree.extend(filter(None, (node.left, node.right)))
        
        

    def insert(self, v):
        """
        :type v: int
        :rtype: int
        """
        node = TreeNode(v)
        n = len(self.tree)
        self.tree.append(node)
        parent = self.tree[(n - 1) // 2]
        if n % 2:
            parent.left = self.tree[-1]
        else:
            parent.right = self.tree[-1]
        return parent.val
        

    def get_root(self):
        """
        :rtype: TreeNode
        """
        return self.tree[0]
        


# Your CBTInserter object will be instantiated and called as such:
# obj = CBTInserter(root)
# param_1 = obj.insert(v)
# param_2 = obj.get_root()