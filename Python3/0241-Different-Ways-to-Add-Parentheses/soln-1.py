class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        funcs = {'+' : operator.add, '-' : operator.sub, '*' : operator.mul}
        def helper(i, j):
            if expression[i:j].isdigit():
                return [int(expression[i:j])]
            else:
                ans = []
                for k in range(i, j):
                    if not expression[k].isdigit():
                        func = funcs[expression[k]]
                        ans.extend([func(left, right) for left, right in itertools.product(helper(i, k), helper(k + 1, j))])
                return ans
        return helper(0, len(expression))
