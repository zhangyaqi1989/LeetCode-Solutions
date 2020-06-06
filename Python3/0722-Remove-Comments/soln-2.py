class Solution:
    def removeComments(self, source: List[str]) -> List[str]:
        s = '\n'.join(source)
        ans = []
        i = 0
        n = len(s)
        while i < n:
            if i + 1 < n and s[i] == '/' and s[i + 1] == '*':
                i += 2
                while i + 1 < n and not (s[i] == '*' and s[i + 1] == '/'):
                    i += 1
                i += 2
            elif i + 1 < n and s[i] == '/' and s[i + 1] == '/':
                i += 2
                while i < n and s[i] != '\n':
                    i += 1
            else:
                ans.append(s[i])
                i += 1
        return [line for line in ''.join(ans).split('\n') if line]
