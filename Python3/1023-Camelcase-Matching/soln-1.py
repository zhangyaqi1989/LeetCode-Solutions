class Solution:
    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        def is_subseq(query, pattern):
            idx, n = 0, len(pattern)
            for ch in query:
                if ch == pattern[idx]:
                    idx += 1
                    if idx == n:
                        return True
            return False

        def caps(word):
            return sum(ch.isupper() for ch in word)
        c = caps(pattern)
        return [True if (is_subseq(word, pattern) and caps(word) == c) else False for word in queries]
