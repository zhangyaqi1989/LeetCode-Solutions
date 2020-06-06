class Solution:
    def gcdOfStrings(self, S: str, T: str) -> str:
        if len(S) > len(T):
            S, T = T, S
        ns, nt = len(S), len(T)
        for i in range(ns, 0, -1):
            if ns % i == 0 and nt % i == 0 and S[:i] * (ns // i) == S and S[:i] * (nt // i) == T:
                return S[:i]
        return ""
