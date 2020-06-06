class Solution:
    def findPoisonedDuration(self, timeSeries, duration):
        """
        :type timeSeries: List[int]
        :type duration: int
        :rtype: int
        """
        ans = 0
        end = float('-inf')
        for time in timeSeries:
            if time >= end:
                ans += duration
            else:
                ans += (duration - (end - time))
            end = time + duration
        return ans