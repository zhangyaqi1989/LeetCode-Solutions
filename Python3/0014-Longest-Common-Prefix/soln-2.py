class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        return ''.join(t[0] for t in
            itertools.takewhile(lambda x : len(set(x)) == 1, zip(*strs)))