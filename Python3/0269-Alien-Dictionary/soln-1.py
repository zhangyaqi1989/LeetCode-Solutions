class Solution:
    def alienOrder(self, words):
        """
        :type words: List[str]
        :rtype: str
        """
        pres, sucs = collections.defaultdict(set), collections.defaultdict(set)
        for w1, w2 in zip(words, words[1:]):
            for a, b in zip(w1, w2):
                if a != b:
                    sucs[a].add(b)
                    pres[b].add(a)
                    break
        chrs = set(''.join(words))
        frees = chrs - pres.keys()
        ans = ''
        while frees:
            ch = frees.pop()
            ans += ch
            if ch in sucs:
                for nei in sucs.pop(ch):
                    if len(pres[nei]) == 1:
                        pres.pop(nei)
                        frees.add(nei)
                    else:
                        pres[nei].remove(ch)
        return ans if len(ans) == len(chrs) else ''