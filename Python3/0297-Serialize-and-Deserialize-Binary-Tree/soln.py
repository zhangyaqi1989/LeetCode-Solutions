# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        vals = []
        def helper(node):
            if not node:
                vals.append('#')
            else:
                vals.append(str(node.val))
                helper(node.left)
                helper(node.right)
        helper(root)
        return '_'.join(vals)
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        vals = iter(data.split('_'))
        def helper():
            val = next(vals)
            if val == '#':
                return None
            else:
                root = TreeNode(int(val))
                root.left = helper()
                root.right = helper()
                return root
        return helper()
# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))