class Solution:
    def alienOrder(self, words):
        """
        :type words: List[str]
        :rtype: str
        """
        pres, sucs = collections.defaultdict(set), collections.defaultdict(set)
        for word1, word2 in zip(words, words[1:]):
            for a, b in zip(word1, word2):
                if a != b:
                    pres[b].add(a)
                    sucs[a].add(b)
                    break
        chars = set(''.join(words))
        frees = chars - pres.keys()
        res = ''
        while frees:
            node = frees.pop()
            res += node
            if node in sucs:
                for nei in sucs.pop(node):
                    if len(pres[nei]) == 1:
                        frees.add(nei)
                        del pres[nei]
                    elif len(pres[nei]) > 1:
                        pres[nei].remove(node)
        return res if len(res) == len(chars) else ''