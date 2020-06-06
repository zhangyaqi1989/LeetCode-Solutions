class Solution:
    def clumsy(self, N: int) -> int:
        ops = [operator.mul, operator.floordiv, operator.add, operator.sub]
        idx = 0
        stack = [N]
        while N > 1:
            N -= 1
            if idx == 0:
                stack.append(ops[idx](stack.pop(), N))
            elif idx == 1:
                top = stack.pop()
                if top >= 0:
                    stack.append(top // N)
                else:
                    stack.append(-(-top // N))
            elif idx == 2:
                stack.append(N)
            else:
                stack.append(-N)
            idx = (idx + 1) % 4
            # print(stack)
        return sum(stack)
