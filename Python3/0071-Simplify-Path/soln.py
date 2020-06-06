class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        stack = []
        for d in path.split('/'):
            if not d or d == '.': continue
            if d == '..':
                if stack:
                    stack.pop()
            else:
                stack.append(d)
        return '/' + '/'.join(stack)