class Solution:
    def boldWords(self, words: List[str], S: str) -> str:
        n = len(S)
        tags = [False] * n
        for word in words:
            m = len(word)
            for i in range(n - m + 1):
                if S[i:i + m] == word:
                    tags[i:i+m] = [True] * m
        ans = []
        for i, ch in enumerate(S):
            if tags[i] and (i == 0 or not tags[i - 1]):
                ans.append("<b>")
            ans.append(ch)
            if tags[i] and (i == n-1 or not tags[i + 1]):
                ans.append("</b>")
        return ''.join(ans)
