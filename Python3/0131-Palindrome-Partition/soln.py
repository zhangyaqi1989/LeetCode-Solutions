class Solution:
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        ans = []
        path = []
        self.helper(s, 0, [], ans)
        return ans
    
    def helper(self, s, idx, path, ans):
        if idx == len(s):
            ans.append(path)
        else:
            for j in range(idx + 1, len(s) + 1):
                if self.isPal(s[idx : j]):
                    self.helper(s, j, path + [s[idx : j]], ans)

    def isPal(self, s):
        "Check if s is palindrome."
        return s == s[::-1]
