# Definition for a undirected graph node
# class UndirectedGraphNode:
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []

class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    def cloneGraph(self, node):
        if not node:
            return None
        visited = {}
        # nodes are labeled uniquely
        visited[node.label] = UndirectedGraphNode(node.label)
        root = visited[node.label]
        stack = [node]
        while stack:
            vertex = stack.pop()
            for nei in vertex.neighbors:
                if nei.label not in visited:
                    visited[nei.label] = UndirectedGraphNode(nei.label)
                    stack.append(nei)
                visited[vertex.label].neighbors.append(visited[nei.label])
        return root