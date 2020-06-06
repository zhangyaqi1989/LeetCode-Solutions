class Solution:
    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        def valid(word):
            i, n = 0, len(pattern)
            for j, ch in enumerate(word):
                if ch == pattern[i]:
                    i += 1
                    if i == n:
                        break
                        # return True
                else:
                    if ch.isupper():
                        return False
            return i == n and all(ch.islower() for ch in word[j + 1:])
        return list(map(valid, queries))
