class Solution:
    def constructRectangle(self, area):
        """
        :type area: int
        :rtype: List[int]
        """
        return min([(area // W, W) for W in range(1, int(math.sqrt(area)) + 1)
            if area % W == 0], key=lambda pair : pair[0] - pair[1])
