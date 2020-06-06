class Solution:
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        counter = collections.Counter(s)
        pairs = [(-value, key) for key, value in counter.items()]
        pairs.sort()
        return ''.join(ch * (-cnt) for cnt, ch in pairs)