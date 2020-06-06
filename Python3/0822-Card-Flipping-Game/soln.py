class Solution:
    def flipgame(self, fronts, backs):
        """
        :type fronts: List[int]
        :type backs: List[int]
        :rtype: int
        """
        dups = {f for f, b in zip(fronts, backs) if f == b}
        nums = list(set(fronts + backs))
        heapq.heapify(nums)
        while nums:
            num = heapq.heappop(nums)
            if num not in dups:
                return num
        return 0
