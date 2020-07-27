# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countPairs(self, root: TreeNode, distance: int) -> int:
        # Compute all values of pairs
        # 1000
        # compute all nodes
        # tree to graph
        graph = collections.defaultdict(list)
        leafs = set()
        def dfs(node):
            if node is not None:
                if node.left is None and node.right is None:
                    leafs.add(node)
                if node.left is not None:
                    graph[node].append(node.left)
                    graph[node.left].append(node)
                    dfs(node.left)
                if node.right is not None:
                    graph[node].append(node.right)
                    graph[node.right].append(node)
                    dfs(node.right)
        dfs(root)
        # print([node.val for node in leafs])
        self.cnt = 0
        def bfs(node):
            seen = {node}
            frontier = [node]
            k = distance
            while frontier:
                next_level = []
                for u in frontier:
                    for v in graph[u]:
                        if v not in seen:
                            seen.add(v)
                            next_level.append(v)
                            self.cnt += v in leafs
                frontier = next_level
                if k == 1:
                    break
                k -= 1
        for node in leafs:
            bfs(node)
        return self.cnt // 2
