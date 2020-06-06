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
        stream = iter(data.split())
        val = int(next(stream))
        root = Node(val, [])
        def build(node):
            while True:
                val = next(stream)
                if val == "#":
                    break
                child = Node(int(val), [])
                node.children.append(child)
                build(child)
        build(root)
        return root
# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
