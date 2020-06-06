class Solution:
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        seen, ans = set(), set()
        for i in range(len(s) - 9):
            ten = s[i : i + 10]
            if ten not in seen:
                seen.add(ten)
            else:
                ans.add(ten)
        return list(ans)