class Solution:
    def letterCasePermutation(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        ans = [""]
        for ch in S:
            if ch.isdigit():
                ans = [sub + ch for sub in ans]
            else:
                ans = [sub + ch for ch in (ch.lower(), ch.upper()) for sub in ans]
        return ans