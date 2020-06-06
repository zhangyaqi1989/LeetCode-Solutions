class Solution:
    def sequenceReconstruction(self, org: List[int], seqs: List[List[int]]) -> bool:
        seqs = [seq for seq in seqs if seq]
        if not seqs:
            return False
        n = len(org)
        degrees = [0] * (n + 1)
        follows = collections.defaultdict(list)
        seen = set()
        for seq in seqs:
            if any(num < 1 or num > n + 1 for num in seq):
                return False
            for a, b in zip(seq, seq[1:]):
                if (a, b) not in seen:
                    degrees[b] += 1
                    seen.add((a, b))
                    follows[a].append(b)
        frees = {i for i in range(1, n + 1) if degrees[i] == 0}
        ans = []
        while frees:
            if len(frees) > 1:
                return False
            node = frees.pop()
            ans.append(node)
            for nei in follows[node]:
                degrees[nei] -= 1
                if degrees[nei] == 0:
                    frees.add(nei)
        return len(ans) == n
