# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distanceK(self, root, target, K):
        """
        :type root: TreeNode
        :type target: TreeNode
        :type K: int
        :rtype: List[int]
        """
        tree = collections.defaultdict(list)
        def dfs(node):
            if node is not None:
                for child in filter(None, [node.left, node.right]):
                    tree[node].append(child)
                    tree[child].append(node)
                    dfs(child)
        dfs(root)
        level = [(target, None)]
        while K > 0 and level:
            K -= 1
            temp = []
            for node, parent in level:
                for nei in tree[node]:
                    if nei != parent:
                        temp.append((nei, node))
            if K == 0:
                return [node.val for node, _ in temp]
            level = temp
        return [node.val for node, _ in level]
