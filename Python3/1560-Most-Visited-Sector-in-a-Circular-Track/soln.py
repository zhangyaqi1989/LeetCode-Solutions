class Solution:
    def mostVisited(self, n: int, rounds: List[int]) -> List[int]:
        nvisits = [0] * n
        m = len(rounds)
        for i in range(m - 1):
            s, e = rounds[i] - 1, rounds[i + 1] - 1
            if e <= s:
                e += n
            for j in range(s, e + 1):
                if i != 0 and j == s:
                    continue
                nvisits[j % n] += 1
        mx = max(nvisits)
        return [i + 1 for i in range(n) if nvisits[i] == mx]
