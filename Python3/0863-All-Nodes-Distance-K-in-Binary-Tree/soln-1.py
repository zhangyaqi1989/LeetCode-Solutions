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
        graph = collections.defaultdict(list)
        def dfs(node):
            if node:
                for nei in (node.left, node.right):
                    if nei:
                        graph[node.val].append(nei.val)
                        graph[nei.val].append(node.val)
                        dfs(nei)
        dfs(root)
        queue = collections.deque([target.val])
        ans = []
        visited = {target.val}
        while queue and K >= 0:
            size = len(queue)
            for _ in range(size):
                node = queue.popleft()
                if K == 0:
                    ans.append(node)
                for nei in graph[node]:
                    if nei not in visited:
                        visited.add(nei)
                        queue.append(nei)
            K -= 1
        return ans
