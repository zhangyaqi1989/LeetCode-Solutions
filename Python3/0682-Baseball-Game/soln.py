class Solution(object):
    def calPoints(self, ops):
        """
        :type ops: List[str]
        :rtype: int
        """
        def isnum(ch):
            try:
                temp = int(ch)
                return True
            except:
                return False
        ans, stack = 0, []
        for op in ops:
            if isnum(op):
                val = int(op)
            elif op == '+':
                val = stack[-1] + stack[-2]
            elif op == 'D':
                val = stack[-1] * 2
            else:
                val = None
            if val is not None:
                ans += val
                stack.append(val)
            else:
                ans -= stack.pop()
        return ans
        