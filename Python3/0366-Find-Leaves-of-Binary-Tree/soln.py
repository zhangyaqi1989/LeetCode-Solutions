# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        graph = collections.defaultdict(set)
        def traverse(node):
            if not node:
                return
            if node.left:
                graph[node].add(node.left)
                graph[node.left].add(node)
            if node.right:
                graph[node].add(node.right)
                graph[node.right].add(node)
            traverse(node.left)
            traverse(node.right)
        traverse(root)
        graph[root].add(root)
        res = []
        while len(graph) > 1: 
            nodes = [node for node in graph if len(graph[node]) == 1]
            for node in nodes:
                nei = graph.pop(node).pop()
                graph[nei].remove(node)
            res.append([node.val for node in nodes])
        res.append([root.val])
        return res