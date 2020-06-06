class WordFilter:

    def __init__(self, words: List[str]):
        self.d = {}
        for w, word in enumerate(words):
            n = len(word)
            for i in range(n + 1):
                pre = word[:i]
                for j in range(n + 1):
                    suf = word[n - j:]
                    self.d[(pre, suf)] = max(self.d.get((pre, suf), -1), w)
        

    def f(self, prefix: str, suffix: str) -> int:
        return self.d.get((prefix, suffix), -1) 


# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(prefix,suffix)
