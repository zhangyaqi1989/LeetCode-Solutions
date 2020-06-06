class Solution:
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        if len(s1) + len(s2) != len(s3):
            return False
        memo = {}
        def helper(p1, p2):
            if (p1, p2) in memo:
                return memo[p1, p2]
            if p1 + p2 == len(s3):
                return True
            match1, match2 = p1 < len(s1) and s1[p1] == s3[p1 + p2], p2 < len(s2) and s2[p2] == s3[p1 + p2]
            if match1 and match2:
                ans = any([helper(p1 + 1, p2), helper(p1, p2 + 1), helper(p1 + 1, p2 + 1)])
            elif match1:
                ans = helper(p1 + 1, p2)
            elif match2:
                ans = helper(p1, p2 + 1)
            else:
                ans = False
            memo[p1, p2] = ans
            return ans
        return helper(0, 0)