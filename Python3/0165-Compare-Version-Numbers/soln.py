class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        for ch1, ch2 in itertools.zip_longest(version1.split('.'), version2.split('.'), fillvalue='0'):
            ch1, ch2 = int(ch1), int(ch2)
            if ch1 < ch2:
                return -1
            elif ch1 > ch2:
                return 1
        return 0