class Solution:
    def kSimilarity(self, A: str, B: str) -> int:
        A_chars = []
        B_chars = []
        for a, b in zip(A, B):
            if a != b:
                A_chars.append(a)
                B_chars.append(b)
        A = ''.join(A_chars)
        B = ''.join(B_chars)
        def neighbors(s):
            neis = []
            n = len(s)
            for i in range(n):
                if s[i] != B[i]:
                    for j in range(i + 1, n):
                        if s[j] != B[j] and s[j] == B[i]:
                            neis.append(s[:i] + s[j] + s[i + 1:j] + s[i] + s[j+1:])
                    return neis
        frontier = collections.deque([(0, A)])
        visited = {A}
        while frontier:
            steps, node = frontier.popleft()
            if node == B:
                return steps
            for nei in neighbors(node):
                if nei not in visited:
                    visited.add(nei)
                    frontier.append((steps + 1, nei))
