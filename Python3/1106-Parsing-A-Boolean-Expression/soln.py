class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        def allf(*args):
            return all(args)
        def anyf(*args):
            return any(args)
        lst = []
        for ch in expression:
            if ch == '&':
                lst.append('allf')
            elif ch == '|':
                lst.append('anyf')
            elif ch == '!':
                lst.append('not')
            elif ch == 't':
                lst.append('True')
            elif ch == 'f':
                lst.append('False')
            else:
                lst.append(ch)
        exp = ''.join(lst)
        # print(exp)
        return eval(exp)
