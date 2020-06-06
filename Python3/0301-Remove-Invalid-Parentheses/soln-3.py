class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        def check(s):
            nopens = 0
            for ch in s:
                if ch == '(':
                    nopens += 1
                elif ch == ')':
                    if nopens == 0:
                        return False
                    nopens -= 1
            return not nopens
        frontier = {s}
        while frontier:
            valids = [item for item in frontier if check(item)]
            if valids:
                return valids
            nxt_level = set()
            for item in frontier:
                n = len(item)
                for i in range(n):
                    nxt_level.add(item[:i] + item[i + 1:])
            frontier = nxt_level
