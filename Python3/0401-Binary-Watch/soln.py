class Solution(object):
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        ans = []
        for h in range(12):
            for m in range(60):
                if bin(h).count('1') + bin(m).count('1') == num:
                    ans.append('{:d}:{:02d}'.format(h, m))
        return ans