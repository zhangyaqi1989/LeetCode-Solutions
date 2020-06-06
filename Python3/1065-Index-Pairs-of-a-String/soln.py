class Solution:
    def indexPairs(self, text: str, words: List[str]) -> List[List[int]]:
        ans = []
        m = len(text)
        for word in words:
            n = len(word)
            for i in range(m - n + 1):
                if text[i:i + n] == word:
                    ans.append([i, i + n - 1])
        return sorted(ans)
