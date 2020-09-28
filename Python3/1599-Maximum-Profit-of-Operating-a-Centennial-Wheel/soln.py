class Solution:
    def minOperationsMaxProfit(self, customers: List[int], boardingCost: int, runningCost: int) -> int:
        nwaits = 0
        best_profit = 0
        best_rotations = 0
        profit = 0
        for i, c in enumerate(itertools.chain(customers, itertools.repeat(0))):
            nwaits += c
            board = min(4, nwaits)
            nwaits -= board
            profit += (board * boardingCost - runningCost)
            if profit > best_profit:
                best_profit = profit
                best_rotations = i + 1
            if i >= len(customers) and nwaits == 0:
                break
        return best_rotations if best_profit > 0 else -1
