import functools
class Solution:
    def backspaceCompare(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """
        def back(stack, c):
            if c != '#': stack.append(c)
            elif stack: stack.pop()
            return stack
        return functools.reduce(back, S, []) == functools.reduce(back, T, [])