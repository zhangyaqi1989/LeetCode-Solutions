class Solution:
    def countSubTrees(self, n: int, edges: List[List[int]], labels: str) -> List[int]:
        tree = [[] for _ in range(n)]
        for u, v in edges:
            tree[u].append(v)
            tree[v].append(u)
        ans = [0] * n
        def postorder(node, parent):
            counter = [0] * 26
            for nei in tree[node]:
                if nei != parent:
                    cur = postorder(nei, node)
                    for i in range(26):
                        counter[i] += cur[i]
            idx = ord(labels[node]) - ord('a')
            counter[idx] += 1
            ans[node] = counter[idx]
            return counter
        postorder(0, -1)
        return ans
