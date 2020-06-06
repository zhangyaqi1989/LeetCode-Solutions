class Solution:
    def wordPatternMatch(self, pattern: str, string: str) -> bool:
        if len(string) < len(pattern):
            return False
        ptos = [None] * 26
        subs = set()
        def dfs(i, j):
            if i == len(pattern) and j == len(string):
                return True
            if i == len(pattern) or j == len(string):
                return False
            if len(pattern) - i > len(string) - j:
                return False
            if ptos[ord(pattern[i]) - 97] is not None:
                sub = ptos[ord(pattern[i]) - 97]
                if string[j:j + len(sub)] != sub:
                    return False
                else:
                    return dfs(i + 1, j + len(sub))
            else:
                for idx in range(j + 1, len(string) + 1):
                    sub = string[j:idx]
                    if sub in subs:
                        continue
                    subs.add(sub)
                    ptos[ord(pattern[i]) - 97] = sub
                    if dfs(i + 1, j + len(sub)):
                        return True
                    subs.remove(sub)
                    ptos[ord(pattern[i]) - 97] = None
                return False
        return dfs(i=0, j=0)
