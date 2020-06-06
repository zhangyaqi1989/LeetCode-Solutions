class Solution:
    def deleteTreeNodes(self, nodes: int, parent: List[int], value: List[int]) -> int:
        tree = collections.defaultdict(list)
        for i, p in enumerate(parent):
            if p != -1:
                tree[p].append(i)
        removed = 0
        def post_order(node):
            # return count, sum
            count, summation = 1, value[node]
            for child in tree[node]:
                c_count, c_sum = post_order(child)
                count += c_count
                summation += c_sum
            if summation == 0:
                nonlocal removed
                removed += count
                count = 0
            return count, summation
        post_order(0)
        return nodes - removed
