class Solution:
    def generateSentences(self, synonyms: List[List[str]], text: str) -> List[str]:
        sets = []
        words = set()
        for u, v in synonyms:
            if u not in words and v not in words:
                sets.append({u, v})
            else:
                for s in sets:
                    if u in s or v in s:
                        s.add(u)
                        s.add(v)
            words.add(u)
            words.add(v)
        tokens = text.split()
        cands = []
        for i, token in enumerate(tokens):
            if token in words:
                for s in sets:
                    if token in s:
                        cands.append(s)
                        break
        template = " ".join(token if token not in words else "{}" for token in tokens)
        ans = []
        for word_comb in itertools.product(*cands):
            ans.append(template.format(*word_comb))
        return sorted(ans)
