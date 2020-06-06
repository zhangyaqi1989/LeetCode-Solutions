class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        res = ''
        for row in zip(*strs):
            if len(set(row)) == 1:
                res += row[0]
            else:
                break
        return res