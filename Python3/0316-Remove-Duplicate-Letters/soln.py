class Solution:
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """

        rindex = {x:i for i,x in enumerate(s)}
        stack = []
        for i,x in enumerate(s):
            if x not in stack:
                while stack and x < stack[-1] and i < rindex[stack[-1]]:
                    stack.pop()
                stack.append(x)
        return ''.join(stack)