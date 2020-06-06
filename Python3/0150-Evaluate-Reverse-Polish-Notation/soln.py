class Solution:
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        ops = {'+' : operator.add, '-' : operator.sub, '*' : operator.mul, '/' : lambda x, y : int(operator.truediv(x, y))}
        stack = []
        for token in tokens:
            if token in ops:
                right, left = stack.pop(), stack.pop()
                stack.append(ops[token](left, right))
            else:
                stack.append(int(token))
        return stack[0]
        