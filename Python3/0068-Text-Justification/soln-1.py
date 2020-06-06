class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        line = []
        ans = []
        nchars = 0
        for w in words:
            if nchars + len(line) + len(w) > maxWidth:
                n = len(line) - 1
                spaces = [0] * (n or 1)
                for i in range(maxWidth - nchars):
                    spaces[i % (n or 1)] += 1
                temp = []
                for i in range((n or 1)):
                    temp.append(line[i])
                    temp.append(' ' * spaces[i])
                if n >= 1:
                    temp.append(line[-1])
                ans.append(''.join(temp))
                line = []
                nchars = 0
            line.append(w)
            nchars += len(w)
        ans.append(' '.join(line).ljust(maxWidth))
        return ans
