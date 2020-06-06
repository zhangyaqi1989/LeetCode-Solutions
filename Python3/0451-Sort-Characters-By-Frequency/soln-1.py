class Solution:
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        return ''.join(key * cnt for key, cnt in collections.Counter(s).most_common())