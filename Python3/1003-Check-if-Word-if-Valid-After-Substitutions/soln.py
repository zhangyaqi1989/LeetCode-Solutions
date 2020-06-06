class Solution:
    def isValid(self, S: str) -> bool:
        if len(S) % 3 != 0:
            return False
        As, Bs = 0, 0
        for ch in S:
            if ch == 'c':
                if not (Bs > 0 and As > 0):
                    return False
                else:
                    Bs -= 1
                    As -= 1
            elif ch == 'b':
                Bs += 1
            else:
                As += 1
            if Bs > As:
                return False
        return As == 0 == Bs
