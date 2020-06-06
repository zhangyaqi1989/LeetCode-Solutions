# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def removeLeafNodes(self, root: TreeNode, target: int) -> TreeNode:
        def postorder(node, parent, is_left=True):
            if node is not None:
                ld = postorder(node.left, node)
                rd = postorder(node.right, node, False)
                if ld and rd and node.val == target:
                    if parent is not None:
                        if is_left:
                            parent.left = None
                        else:
                            parent.right = None
                    return True
                return False
            else:
                return True
        d = postorder(root, None)
        return None if d else root
