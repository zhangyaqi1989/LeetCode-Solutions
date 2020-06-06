class Solution:
    # TLE
    def countOfAtoms(self, formula: str) -> str:
        stack = [[1, ""]]
        cnt = ""
        atom = ""
        for ch in reversed(formula):
            if ch.isalpha():
                atom = ch + atom
                if ch.isupper():
                    cnt = 1 if not cnt else int(cnt)
                    stack[-1][-1] += atom * cnt
                    cnt = ""
                    atom = ""
            elif ch.isdigit():
                cnt = ch + cnt
            elif ch == ')':
                stack.append([int(cnt), ""])
                cnt = ""
            else: # ch == '('
                num, pattern = stack.pop()
                stack[-1][-1] += pattern * num
        lo = 0
        counter = collections.Counter()
        s = stack[-1][-1] + 'A'
        for i, ch in enumerate(s):
            if ch.isupper():
                counter[s[lo:i]] += 1
                lo = i
        return ''.join(ch + (str(counter[ch] if counter[ch] > 1 else "")) for ch in sorted(counter))
