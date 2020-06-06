class Solution(object):
    def minMutation(self, start, end, bank):
        """
        :type start: str
        :type end: str
        :type bank: List[str]
        :rtype: int
        """
        # this is a bi-direction BFS
        bank = set(bank)
        if end not in bank:
            return -1
        step = 0
        s1, s2 = {start}, {end}
        bank.discard(start)
        while s1 and s2:
            if len(s2) < len(s1):
                s1, s2 = s2, s1
            step += 1
            s = set()
            for gene in s1:
                for idx in range(8):
                    for ch in ('A', 'C', 'G', 'T'):
                        new_gene = gene[:idx] + ch + gene[idx + 1:]
                        if new_gene in s2: # do not put this check below
                            return step
                        if new_gene in bank:
                            bank.remove(new_gene)
                            s.add(new_gene)
            s1 = s
        return -1
                    