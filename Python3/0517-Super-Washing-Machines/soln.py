class Solution:
    def findMinMoves(self, machines):
        """
        :type machines: List[int]
        :rtype: int
        """
        avg, r = divmod(sum(machines), len(machines))
        if r != 0:
            return -1
        to_left = 0
        ans = 0
        for num in machines:
            to_right = num - to_left - avg
            ans = max(ans, to_left, to_right, to_left + to_right)
            to_left = -to_right
        return ans
