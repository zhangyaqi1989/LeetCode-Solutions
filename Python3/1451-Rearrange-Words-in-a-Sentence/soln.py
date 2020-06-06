class Solution:
    def arrangeWords(self, text: str) -> str:
        words = [(word.lower(), i) for i, word in enumerate(text.split())]
        words.sort(key=lambda x : (len(x[0]), x[1]))
        ans = ' '.join(w for w, _ in words)
        ans = ans[0].upper() + ans[1:]
        return ans
