# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getLonelyNodes(self, root: TreeNode) -> List[int]:
        def dfs(node):
            if node is not None:
                children = list(filter(None, [node.left, node.right]))
                if len(children) == 1:
                    ans.append(children[0].val)
                for child in children:
                    dfs(child)
        ans = []
        dfs(root)
        return ans
