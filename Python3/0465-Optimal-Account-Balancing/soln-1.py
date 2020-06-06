class Solution:
    def minTransfers(self, transactions):
        """
        :type transactions: List[List[int]]
        :rtype: int
        """
        # x gave y $z
        debts = collections.defaultdict(int)
        for x, y, z in transactions:
            debts[x] -= z
            debts[y] += z
        nonzeros = [num for num in debts.values() if num != 0]
        ans = len(nonzeros)
        def bfs():
            queue = collections.deque([[[0], nonzeros[0]]])
            n = len(nonzeros)
            while queue:
                sub, num = queue.popleft()
                if num == 0:
                    min_zero_set = sub
                    break
                for j in range(sub[-1] + 1, n):
                    queue.append([sub + [j], num + nonzeros[j]])
            min_zero_set = set(min_zero_set)
            return [num for i, num in enumerate(nonzeros) if i not in min_zero_set]
        while nonzeros:
            nonzeros = bfs()
            ans -= 1
        return ans