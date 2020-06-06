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
        def preorder(node):
            if node is not None:
                vals.append(str(node.val))
                if node.left is not None:
                    preorder(node.left)
                else:
                    vals.append('#')
                if node.right is not None:
                    preorder(node.right)
                else:
                    vals.append('#')
        preorder(root)
        return ' '.join(vals)
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        # print(data)
        vals = iter(data.split())
        def build():
            val = next(vals, None)
            if val == '#' or val is None:
                return None
            else:
                node = TreeNode(int(val))
                node.left = build()
                node.right = build()
                return node
        return build()
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
