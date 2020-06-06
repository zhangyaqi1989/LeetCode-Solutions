# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def distanceK(self, root, target, K):
        """
        :type root: TreeNode
        :type target: TreeNode
        :type K: int
        :rtype: List[int]
        """
        # BFS in a graph
        if K == 0:
            return [target.val]
        graph = collections.defaultdict(list)
        def traverse(node):
            if node:
                for nei in node.left, node.right:
                    if nei:
                        graph[node].append(nei)
                        graph[nei].append(node)
                        traverse(nei)
        traverse(root)
        queue = collections.deque([target])
        visited = {target}
        while queue:
            size = len(queue)
            for _ in range(size):
                node = queue.popleft()
                for nei in graph[node]:
                    if nei not in visited:
                        visited.add(nei)
                        queue.append(nei)
            K -= 1
            if K == 0:
                return [node.val for node in queue]
        return []