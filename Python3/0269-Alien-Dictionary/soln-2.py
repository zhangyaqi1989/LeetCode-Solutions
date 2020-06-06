class Solution:
    def alienOrder(self, words: List[str]) -> str:
        degrees = collections.Counter()
        follows = collections.defaultdict(list)
        n = len(words)
        chars = set()
        for w in words:
            for ch in w:
                chars.add(ch)
        for i in range(n - 1):
            w1, w2 = words[i], words[i + 1]
            for a, b in zip(w1, w2):
                if a != b:
                    degrees[b] += 1
                    follows[a].append(b)
                    break
        frees = []
        for ch in chars:
            if not degrees[ch]:
                frees.append(ch)
        ans = []
        while frees:
            ch = frees.pop()
            ans.append(ch)
            for nei in follows[ch]:
                degrees[nei] -= 1
                if not degrees[nei]:
                    frees.append(nei)
        return ''.join(ans) if len(ans) == len(chars) else ""
