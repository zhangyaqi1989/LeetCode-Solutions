class Solution:
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        d = collections.defaultdict(list)
        for string in strs:
            d[''.join(sorted(string))].append(string)
        return list(d.values())