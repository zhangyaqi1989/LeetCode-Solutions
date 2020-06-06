class Solution:
    def printVertically(self, s: str) -> List[str]:
        tokens = s.split()
        n = max(len(t) for t in tokens)
        lst = []
        for chs in itertools.zip_longest(*tokens, fillvalue=' '):
            lst.append(''.join(chs).rstrip())
        return lst
