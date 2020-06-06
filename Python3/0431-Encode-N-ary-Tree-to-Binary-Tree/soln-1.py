"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
"""
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
"""
class Codec:

    def encode(self, root):
        """Encodes an n-ary tree to a binary tree.
        
        :type root: Node
        :rtype: TreeNode
        """
        if root is None:
            return None
        else:
            node = TreeNode(root.val)
            node.left = self.encode(root.children[0]) if root.children else None
            cur = node.left
            for i in range(1, len(root.children)):
                cur.right = self.encode(root.children[i])
                cur = cur.right
            return node
        

    def decode(self, root):
        """Decodes your binary tree to an n-ary tree.
        
        :type root: TreeNode
        :rtype: Node
        """
        if root is None:
            return None
        else:
            node = Node(root.val, [])
            cur = root.left
            children = node.children
            while cur is not None:
                children.append(self.decode(cur))
                cur = cur.right
            return node
            
            
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(root))
