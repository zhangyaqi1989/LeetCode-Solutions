class Solution:
    def calculate(self, s: str) -> int:
        stacks = [[0, 1]]
        val = ""
        sign = 1
        for i, ch in enumerate(s):
            if ch == ' ':
                continue
            if ch == '(':
                stacks[-1][-1] = sign
                stacks.append([0, 1])
                sign = 1
            elif ch in "+-":
                if val:
                    stacks[-1][0] += sign * int(val)
                    val = ""
                sign = 1 if ch == '+' else -1
            elif ch == ')':
                if val:
                    stacks[-1][0] += sign * int(val)
                    val = ""
                    sign = 1
                top = stacks.pop()[0]
                stacks[-1][0] += stacks[-1][1] * top
            else:
                val += ch
        if val:
            stacks[-1][0] += sign * int(val)
        return stacks[-1][0]
