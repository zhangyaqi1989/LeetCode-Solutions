class Solution(object):
    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        def isValid(s):
            cnt = 0
            for ch in s:
                if ch == '(':
                    cnt += 1
                elif ch == ')':
                    cnt -= 1
                    if cnt < 0:
                        return False
            return cnt == 0
        level = {s}
        while True:
            valid = filter(isValid, level)
            if valid:
                return valid
            level = {item[:i] + item[i+1:] for item in level for i in range(len(item))}