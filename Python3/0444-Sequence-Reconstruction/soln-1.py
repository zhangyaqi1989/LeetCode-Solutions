class Solution:
    def sequenceReconstruction(self, org, seqs):
        """
        :type org: List[int]
        :type seqs: List[List[int]]
        :rtype: bool
        """
        if len(org) and not any(seqs): return False
        n = len(org)
        pos = [0] * (n + 1)
        flags = [0] * (n + 1)
        for i, val in enumerate(org):
            pos[val] = i
        to_match = n - 1
        for seq in seqs:
            for i, val in enumerate(seq):
                if val <= 0 or val > n: return False
                if i == 0: continue
                x, y = seq[i - 1], val
                if pos[x] >= pos[y]: return False
                if (flags[x] == 0 and pos[x] + 1 == pos[y]):
                    flags[x] = 1
                    to_match -= 1
        return to_match == 0