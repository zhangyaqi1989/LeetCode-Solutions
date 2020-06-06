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
        cur, stack = root, []
        while cur or stack:
            while cur:
                vals.append(cur.val)
                stack.append(cur)
                cur = cur.left
            cur = stack.pop()
            cur = cur.right
        return ' '.join(map(str, vals))
        
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        vals = list(map(int, data.split()))
        def build(vals):
            if not vals:
                return None
            root_val = vals[0]
            root = TreeNode(root_val)
            i = 1
            while i < len(vals) and vals[i] < root_val:
                i += 1
            root.left = build(vals[1:i])
            root.right = build(vals[i:])
            return root
        return build(vals)
        
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
