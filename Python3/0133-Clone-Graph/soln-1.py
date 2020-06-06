# Definition for a undirected graph node
# class UndirectedGraphNode:
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []

class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    def cloneGraph(self, node):
        # nodes are labely unique
        if node is None: return None
        stack, visited = [node], {node.label: UndirectedGraphNode(node.label)}
        while stack:
            v = stack.pop()
            for nei in v.neighbors:
                if nei.label not in visited:
                    visited[nei.label] = UndirectedGraphNode(nei.label)
                    stack.append(nei)
                visited[v.label].neighbors.append(visited[nei.label])
        return visited[node.label]