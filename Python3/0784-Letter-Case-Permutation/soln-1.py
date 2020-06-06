class Solution:
    def letterCasePermutation(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        ans = []
        self.helper(0, S, [], ans)
        return ans
        
    def helper(self, idx, S, permu, ans):
        if idx == len(S):
            ans.append(''.join(permu))
            return
        if S[idx].isalpha():
            for ch in (S[idx].lower(), S[idx].upper()):
                self.helper(idx + 1, S, permu + [ch], ans)
        else:
            self.helper(idx + 1, S, permu + [S[idx]], ans)