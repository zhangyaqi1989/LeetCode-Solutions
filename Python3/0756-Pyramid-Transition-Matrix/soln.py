class Solution:
    def pyramidTransition(self, bottom, allowed):
        """
        :type bottom: str
        :type allowed: List[str]
        :rtype: bool
        """
        possibles = collections.defaultdict(list)
        for a, b, c in allowed:
            possibles[a, b].append(c)
        def valid(bottom):
            if len(bottom) == 1:
                return True
            cands = [possibles[bottom[i], bottom[i + 1]] for i in range(len(bottom) - 1)]
            return any(valid(''.join(lst)) for lst in itertools.product(*cands))
        return valid(bottom)
