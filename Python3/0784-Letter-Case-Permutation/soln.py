class Solution:
    def letterCasePermutation(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        res = []
        self.helper(S, 0, "", res)
        return res
        
    def helper(self, S, idx, path, res):
        if idx == len(S):
            res.append(path)
            return
        if S[idx].isalpha():
            lower, upper = S[idx].lower(), S[idx].upper()
            self.helper(S, idx + 1, path + lower, res)
            self.helper(S, idx + 1, path + upper, res)
        else:
            self.helper(S, idx + 1, path + S[idx], res)