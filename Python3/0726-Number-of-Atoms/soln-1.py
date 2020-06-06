class Solution:
    def countOfAtoms(self, formula: str) -> str:
        stack = [[1, collections.Counter()]]
        cnt, atom = "", ""
        for ch in reversed(formula):
            if ch.isalpha():
                atom = ch + atom
                if ch.isupper():
                    cnt = 1 if not cnt else int(cnt)
                    stack[-1][-1][atom] += cnt
                    cnt, atom = "", ""
            elif ch.isdigit():
                cnt = ch + cnt
            elif ch == ')':
                stack.append([int(cnt), collections.Counter()])
                cnt = ""
            else: # ch == '('
                num, counter  = stack.pop()
                for ch, c in counter.items():
                    stack[-1][-1][ch] += num * c
        counter = stack[-1][-1]
        return ''.join(ch + (str(counter[ch] if counter[ch] > 1 else "")) for ch in sorted(counter))
