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
        def preorder(root):
            if root:
                vals.append(root.val)
                preorder(root.left)
                preorder(root.right)
        vals = []
        preorder(root)
        return ' '.join(map(str, vals))
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        # pre: [2, 1, 3]
        # in: [1, 2, 3]
        preorder = list(map(int, data.split()))
        inorder = sorted(preorder)
        def buildBST(preorder, inorder):
            if not preorder:
                return None
            root_val = preorder[0]
            root = TreeNode(root_val)
            idx = inorder.index(root_val)
            root.left, root.right = buildBST(preorder[1:1 + idx], inorder[:idx]), buildBST(preorder[1+idx:], inorder[idx+1:])
            return root
            
        return buildBST(preorder, inorder)
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))