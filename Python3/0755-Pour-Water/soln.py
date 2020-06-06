class Solution:
    def pourWater(self, heights, V, K):
        """
        :type heights: List[int]
        :type V: int
        :type K: int
        :rtype: List[int]
        """
        heights = list(heights) # keep function pure
        n = len(heights)
        for _ in range(V):
            idx = K
            # try left
            for i in reversed(range(K)):
                if heights[i] > heights[i + 1]:
                    break
                elif heights[i] < heights[i + 1]:
                    idx = i
                    
            if idx != K:
                heights[idx] += 1
                continue
            for i in range(K + 1, n):
                if heights[i] > heights[i - 1]:
                    break
                elif heights[i] < heights[i - 1]:
                    idx = i
            heights[idx] += 1
        return heights
