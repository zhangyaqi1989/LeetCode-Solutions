class Solution:
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        min_idx = len(s)
        for ch in string.ascii_lowercase:
            l, r = s.find(ch), s.rfind(ch)
            if l == r != -1 and l < min_idx:
                min_idx = l
        return min_idx if min_idx != len(s) else -1