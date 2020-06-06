class Solution:
    def alienOrder(self, words: List[str]) -> str:
        n = len(words)
        indegrees = [0] * 26
        outs = collections.defaultdict(set)
        for i in range(1, n):
            w1, w2 = words[i - 1], words[i]
            for c1, c2 in zip(w1, w2):
                if c1 != c2:
                    if c2 not in outs[c1]:
                        indegrees[ord(c2) - 97] += 1
                        outs[c1].add(c2)
                    break
        chars = set()
        for word in words:
            chars |= set(word)
        frees = [ch for ch in chars if not indegrees[ord(ch) - 97]]
        ans = []
        while frees:
            ch = frees.pop()
            ans.append(ch)
            for nei in outs[ch]:
                indegrees[ord(nei) - 97] -= 1
                if not indegrees[ord(nei) - 97]:
                    frees.append(nei)
        return ''.join(ans) if len(ans) == len(chars) else ""
