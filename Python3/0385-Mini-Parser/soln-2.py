# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def add(self, elem):
#        """
#        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#        :rtype void
#        """
#
#    def setInteger(self, value):
#        """
#        Set this NestedInteger to hold a single integer equal to value.
#        :rtype void
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

class Solution:
    def deserialize(self, s: str) -> NestedInteger:
        # if s.isdigit():
        #     return NestedInteger(int(s))
        stack = [[]]
        num = []
        for ch in s:
            if ch == '[':
                stack.append([])
            elif ch == ']':
                if num:
                    stack[-1].append(int(''.join(num)))
                    num = []
                top = stack.pop()
                stack[-1].append(top)
            elif ch == ',':
                if num:
                    stack[-1].append(int(''.join(num)))
                    num = []
            else:
                num.append(ch)
        if num:
            stack[-1].append(int(''.join(num)))
        x = stack[0][0]
        def helper(x):
            if isinstance(x, int):
                return NestedInteger(x)
            ans = NestedInteger()
            for item in x:
                ans.add(helper(item))
            return ans
        return helper(x)
