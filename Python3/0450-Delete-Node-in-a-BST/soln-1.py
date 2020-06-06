# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        if root:
            if key < root.val:
                root.left = self.deleteNode(root.left, key)
            elif key > root.val:
                root.right = self.deleteNode(root.right, key)
            else:
                if not root.left and not root.right:
                    return None
                else:
                    if root.right:
                        root.val = self.successor(root)
                        root.right = self.deleteNode(root.right, root.val)
                    else:
                        root.val = self.predecessor(root)
                        root.left = self.deleteNode(root.left, root.val)
            return root
        else:
            return None
        
    def successor(self, root):
        cur = root.right
        while cur.left:
            cur = cur.left
        return cur.val
    
    def predecessor(self, root):
        cur = root.left
        while cur.right:
            cur = cur.right
        return cur.val
        
