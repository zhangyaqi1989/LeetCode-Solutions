class Solution:
    def canConvertString(self, s: str, t: str, k: int) -> bool:
        if len(s) != len(t):
            return False
        ds = collections.Counter()
        for sc, tc in zip(s, t):
            if sc != tc:
                ds[(ord(tc) - ord(sc)) % 26] += 1
        for d, cnt in ds.items():
            mx = d + (cnt - 1) * 26
            if mx > k:
                return False
        return True
