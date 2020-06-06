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
        data = []
        def preorder(node):
            if node:
                data.append(str(node.val))
                preorder(node.left)
                preorder(node.right)
            else:
                data.append('#')
        preorder(root)
        return ' '.join(data)
        
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        # print(data)
        stream = iter(data.split())
        def build():
            val = next(stream, None)
            if val == '#':
                return None
            else:
                root = TreeNode(int(val))
                root.left = build()
                root.right = build()
                return root
        return build()
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
