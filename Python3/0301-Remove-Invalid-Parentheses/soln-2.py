class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        def is_valid(s):
            cnt = 0
            for ch in s:
                if ch == '(':
                    cnt += 1
                elif ch == ')':
                    cnt -= 1
                    if cnt < 0:
                        return False
            return cnt == 0
        level = {s}
        while True:
            valids = list(filter(is_valid, level))
            if valids:
                return valids
            level = {item[:i] + item[i + 1:] for item in level for i in range(len(item))}
