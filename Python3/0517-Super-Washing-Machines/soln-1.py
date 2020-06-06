class Solution:
    def findMinMoves(self, machines: List[int]) -> int:
        target, r = divmod(sum(machines), len(machines))
        if r != 0:
            return -1
        ans = 0
        to_left = 0
        for cloth in machines:
            to_right = cloth - target - to_left
            ans = max(ans, to_left, to_right, to_left + to_right)
            to_left = -to_right
        return ans
