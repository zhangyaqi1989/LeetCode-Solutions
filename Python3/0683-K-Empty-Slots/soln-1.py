class Solution:
    def kEmptySlots(self, bulbs: List[int], K: int) -> int:
        n = len(bulbs)
        tree = [0] * (n + 1)
        def add(idx, val):
            while idx < len(tree):
                tree[idx] += val
                idx += (idx & (-idx))
        def acc(idx):
            ans = 0
            while idx > 0:
                ans += tree[idx]
                idx -= (idx & (-idx))
            return ans
        ons = set()
        for i, b in enumerate(bulbs):
            add(b, 1)
            if b + K + 1 in ons and acc(b + K + 1) - acc(b) == 1:
                return i + 1
            if b - K - 1 in ons and acc(b) - acc(b - K - 1) == 1:
                return i + 1
            ons.add(b)
        return -1
