class Solution:
    def sequenceReconstruction(self, org, seqs):
        """
        :type org: List[int]
        :type seqs: List[List[int]]
        :rtype: bool
        """
        if not seqs: return False
        seqs = [seq for seq in seqs if seq]
        if not seqs: return False
        n = len(org)
        pos = [0] * (n + 1)
        flags = [0] * (n + 1)
        toMatch = n - 1
        for i, val in enumerate(org):
            pos[val] = i
        for seq in seqs:
            for i, val in enumerate(seq):
                if val <= 0 or val > n: return False
                if i == 0: continue
                x, y = seq[i - 1], val
                if pos[x] >= pos[y]: return False
                if (flags[x] == 0 and pos[x] + 1 == pos[y]):
                    flags[x] = 1
                    toMatch -= 1
        return toMatch == 0