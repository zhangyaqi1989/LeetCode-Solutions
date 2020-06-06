class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split(' ')
        if len(pattern) != len(words):
            return False
        ptow, wtop = {}, {}
        for p, w in zip(pattern, words):
            ptow[p] = ptow.get(p, len(ptow))
            wtop[w] = wtop.get(w, len(wtop))
            if ptow[p] != wtop[w]:
                return False
        return True
