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
            cands = (S[idx].lower(), S[idx].upper())
        else:
            cands = (S[idx])
        for ch in cands:
            permu.append(ch)
            self.helper(idx + 1, S, permu, ans)
            permu.pop()