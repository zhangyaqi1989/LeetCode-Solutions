class Solution:
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        if len(s1) > len(s2): return False
        missing = collections.Counter(s1)
        chrs = set(s1)
        n = len(s1)
        for i, ch in enumerate(s2):
            if i >= n:
                left = s2[i - n]
                if left in chrs:
                    missing[left] += 1
                    if missing[left] == 0:
                        missing.pop(left)
            if ch in chrs:
                missing[ch] -= 1
                if missing[ch] == 0:
                    missing.pop(ch)
            if not missing:
                return True
        return False