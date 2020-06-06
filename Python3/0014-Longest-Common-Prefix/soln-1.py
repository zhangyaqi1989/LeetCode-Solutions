class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs: return ""
        min_str, max_str = strs[0], strs[0]
        for string in strs[1:]:
            if string < min_str:
                min_str = string
            if string > max_str:
                max_str = string
        for i, ch in enumerate(min_str):
            if max_str[i] != ch:
                return min_str[:i]
        return min_str