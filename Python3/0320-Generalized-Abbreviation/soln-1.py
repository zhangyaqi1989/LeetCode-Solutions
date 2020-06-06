class Solution:
    def generateAbbreviations(self, word):
        """
        :type word: str
        :rtype: List[str]
        """
        ans = []
        def helper(word, pos, cur, cnt):
            if pos == len(word):
                ans.append(cur + (str(cnt) if cnt > 0 else ''))
            else:
                helper(word, pos + 1, cur + (str(cnt) if cnt > 0 else '') + word[pos], 0)
                helper(word, pos + 1, cur, cnt + 1)
        helper(word, 0, '', 0)
        return ans