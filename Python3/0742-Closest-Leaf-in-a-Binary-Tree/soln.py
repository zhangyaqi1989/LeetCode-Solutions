# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findClosestLeaf(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        # change this to a search problem
        leafs = set()
        graph = collections.defaultdict(list)
        queue = collections.deque([k])
        def traverse(node):
            if node:
                if not node.left and not node.right:
                    leafs.add(node.val) # record leafs
                else:
                    for nei in ((node.left, node.right)):
                        if nei:
                            graph[node.val].append(nei.val)
                            graph[nei.val].append(node.val)
                            traverse(nei)
        traverse(root)
        visited = {k}
        while queue:
            node = queue.popleft()
            if node in leafs:
                return node
            for nei in graph[node]:
                if nei not in visited:
                    visited.add(nei)
                    queue.append(nei)
                