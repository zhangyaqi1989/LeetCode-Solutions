class Solution(object):
    def nextClosestTime(self, time):
        """
        :type time: str
        :rtype: str
        """
        s = set(time)
        return min((t <= time, t) for i in range(24 * 60) for t in ('{:02d}:{:02d}'.format(*divmod(i, 60)),) if set(t) <= s)[1]