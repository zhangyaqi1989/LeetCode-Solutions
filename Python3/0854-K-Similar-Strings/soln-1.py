class Solution:
    def kSimilarity(self, A: str, B: str) -> int:
        chars_A, chars_B = [], []
        for a, b in zip(A, B):
            if a != b:
                chars_A.append(a)
                chars_B.append(b)
        A = ''.join(chars_A)
        B = ''.join(chars_B)
        def neighbor(A, idx):
            n = len(A)
            chars = list(A)
            for i in range(idx, n):
                if A[i] != B[i]:
                    for j in range(i + 1, n):
                        if A[j] == B[i] and A[j] != B[j]:
                            chars[i], chars[j] = chars[j], chars[i]
                            yield ''.join(chars), i + 1
                            chars[i], chars[j] = chars[j], chars[i]
                    break
        frontier = [(A, 0)]
        levels = {A : 0}
        step = 0
        while frontier:
            nxt_level = []
            for s, idx in frontier:
                if s == B:
                    return levels[s]
                for nei, nei_idx in neighbor(s, idx):
                    if nei not in levels:
                        levels[nei] = step + 1
                        nxt_level.append((nei, nei_idx))
            step += 1
            frontier = nxt_level
