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
        head = None
        stack = []
        for val in vals:
            if head is None:
                head = TreeNode(val)
                stack.append(head)
            else:
                node = TreeNode(val)
                if val < stack[-1].val:
                    stack[-1].left = node
                    stack.append(node)
                else:
                    while stack and stack[-1].val < val:
                        pre = stack.pop()
                    pre.right = node
                    stack.append(node)
        return head
             

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
