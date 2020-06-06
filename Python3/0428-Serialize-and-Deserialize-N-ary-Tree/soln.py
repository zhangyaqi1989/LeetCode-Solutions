"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: Node
        :rtype: str
        """
        vals = []
        def preorder(node):
            if node:
                vals.append(str(node.val))
                for child in node.children:
                    preorder(child)
                vals.append('#')
        preorder(root)
        return ' '.join(vals)
        
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: Node
        """
        if not data:
            return None
        vals = collections.deque(data.split())
        root = Node(int(vals.popleft()), [])
        def helper(node):
            if not vals:
                return None
            while vals[0] != '#':
                child = Node(int(vals.popleft()), [])
                node.children.append(child)
                helper(child)
            vals.popleft()
        helper(root)
        return root
# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))