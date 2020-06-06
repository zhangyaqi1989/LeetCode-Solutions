class Solution:
    def areSentencesSimilar(self, words1, words2, pairs):
        """
        :type words1: List[str]
        :type words2: List[str]
        :type pairs: List[List[str]]
        :rtype: bool
        """
        if len(words1) != len(words2):
            return False
        sims = collections.defaultdict(set)
        for a, b in pairs:
            sims[a].add(b)
        return all(w1 == w2 or w2 in sims[w1] or w1 in sims[w2] for w1, w2 in zip(words1, words2))