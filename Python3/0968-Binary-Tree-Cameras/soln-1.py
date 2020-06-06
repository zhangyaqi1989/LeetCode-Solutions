# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minCameraCover(self, root: TreeNode) -> int:
        # 0: not covered
        # 1: covered, without camera on it
        # 2: covered, with camera on it
        self.cameras = 0
        def postorder(node):
            if node:
                l, r = postorder(node.left), postorder(node.right)
                if l == 0 or r == 0:
                    self.cameras += 1
                    return 2
                elif l == 2 or r == 2:
                    return 1
                else:
                    return 0
            else:
                return 1
        if postorder(root) == 0:
            self.cameras += 1
        return self.cameras
        
