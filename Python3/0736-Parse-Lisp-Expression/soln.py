class Scope:
    def __init__(self, op):
        self.vars = {}
        self.stack = []
        self.op = op

class Solution:
    def evaluate(self, expression: str) -> int:
        expression = expression.replace(')', ' )')
        def query(var):
            if type(var) == int:
                return var
            else:
                for scope in reversed(scops):
                    if var in scope.vars:
                        return scope.vars[var]
            return var
        def evaluate(scope):
            if scope.op == 'let':
                return query(scope.stack[-1])
            else:
                rhs = query(scope.stack[-1])
                lhs = query(scope.stack[-2])
                if scope.op == 'add':
                    return lhs + rhs
                else:
                    return lhs * rhs
                
        scops = []
        i = 0
        token = ""
        while i < len(expression):
            ch = expression[i]
            if ch == ' ':
                if token:
                    try:
                        num = int(token)
                        scops[-1].stack.append(num)
                    except:
                        if scops[-1].op != 'let':
                            scops[-1].stack.append(query(token))
                        else:
                            scops[-1].stack.append(token)
                    if scops[-1].op == 'let' and len(scops[-1].stack) == 2:
                        num = scops[-1].stack.pop()
                        var = scops[-1].stack.pop()
                        scops[-1].vars[var] = query(num)
                    token = ""
            elif ch == '(':
                idx = expression.find(' ', i)
                op = expression[i + 1:idx]
                i = idx + 1
                scops.append(Scope(op))
                continue
            elif ch == ')':
                scp = scops[-1]
                val = evaluate(scp)
                scops.pop()
                if scops:
                    scops[-1].stack.append(query(val))
                    if scops[-1].op == 'let' and len(scops[-1].stack) == 2:
                        num = scops[-1].stack.pop()
                        var = scops[-1].stack.pop()
                        scops[-1].vars[var] = query(num)                        
                else:
                    return val
            else:
                token += ch
            i += 1
