class Solution:
    def nextClosestTime(self, time):
        """
        :type time: str
        :rtype: str
        """
        # there are constant number of times
        time_s = set(time)
        return min((t <= time, t) for i in range(24 * 60) for t in ['%02d:%02d' % divmod(i, 60)] if set(t) <= time_s)[1]