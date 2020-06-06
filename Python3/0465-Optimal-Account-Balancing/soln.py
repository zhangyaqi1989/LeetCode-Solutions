class Solution:
    def minTransfers(self, transactions):
        """
        :type transactions: List[List[int]]
        :rtype: int
        """
        d = collections.Counter()
        for a, b, money in transactions:
            d[a] -= money
            d[b] += money
        poss, negs = [val for val in d.values() if val > 0], [val for val in d.values() if val < 0]
        queue = collections.deque([[poss, negs, 0]])
        while queue:
            pos, neg, num = queue.popleft()
            if not pos and not neg:
                return num
            try:
                idx = neg.index(-pos[0])
                queue.append([pos[1:], neg[:idx] + neg[idx + 1:], num + 1])
                continue
            except ValueError:
                for idx, value in enumerate(neg):
                    if pos[0] + value < 0:
                        queue.append([pos[1:], neg[:idx] + [neg[idx] + pos[0]] + neg[idx + 1:], num + 1])
                    else:
                        queue.append([[pos[0] + value] + pos[1:], neg[:idx] + neg[idx + 1:], num + 1])
        return 0