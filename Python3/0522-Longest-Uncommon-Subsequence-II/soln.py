class Solution:
    def findLUSlength(self, strs):
        """
        :type strs: List[str]
        :rtype: int
        """
        def is_subsequence(string, sub):
            "Check if sub is subssequence of string."
            i = 0
            for ch in string:
                if ch == sub[i]:
                    i += 1
                    if i == len(sub):
                        return True
            return i == len(sub)
        strs = sorted(strs, key=len, reverse=True)
        for i, sub in enumerate(strs):
            if all(not is_subsequence(string, sub)
                   for j, string in enumerate(strs) 
                   if i != j):
                return len(sub)
        return -1