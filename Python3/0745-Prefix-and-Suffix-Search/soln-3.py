# TLE
class WordFilter:

    def __init__(self, words: List[str]):
        self.pres = collections.defaultdict(set)
        self.sufs = collections.defaultdict(set)
        for w, word in enumerate(words):
            n = len(word)
            for i in range(n + 1):
                self.pres[word[:i]].add(w)
                self.sufs[word[n - i:]].add(w)
        

    def f(self, prefix: str, suffix: str) -> int:
        ws = (self.pres[prefix] & self.sufs[suffix])
        return max(ws) if ws else -1


# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(prefix,suffix)
