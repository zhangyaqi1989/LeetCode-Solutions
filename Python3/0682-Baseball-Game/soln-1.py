class Solution(object):
    def calPoints(self, ops):
        """
        :type ops: List[str]
        :rtype: int
        """
        ans, stack = 0, []
        for op in ops:
            if op == '+':
                val = stack[-1] + stack[-2]
            elif op == 'D':
                val = stack[-1] * 2
            elif op == 'C':
                val = None
            else:
                val = int(op)
            if val is not None:
                ans += val
                stack.append(val)
            else:
                ans -= stack.pop()
        return ans
        