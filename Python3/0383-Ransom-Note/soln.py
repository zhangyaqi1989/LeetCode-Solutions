class Solution:
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        cr, cm = collections.Counter(ransomNote), collections.Counter(magazine)
        return all(cm[ch] >= cr[ch] for ch in string.ascii_lowercase)