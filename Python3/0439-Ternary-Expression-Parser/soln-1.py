class Solution:
    def parseTernary(self, expression: str) -> str:
        while True:
            idx = expression.rfind('?')
            if idx == -1:
                return expression
            else:
                TF = expression[idx - 1]
                if TF == 'T':
                    res = expression[idx + 1]
                else:
                    res = expression[idx + 3]
                expression = expression[:idx - 1] + res + expression[idx + 4:]
