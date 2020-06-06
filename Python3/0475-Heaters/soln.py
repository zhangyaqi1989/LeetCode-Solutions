class Solution:
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        heaters = [float('-inf')] + heaters + [float('inf')]
        heaters.sort()
        radius, i = 0, 0
        for house in sorted(houses):
            while heaters[i] < house:
                i += 1
            radius = max(radius, min(heaters[i] - house, house - heaters[i - 1]))
        return radius
