class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy"]
        ch = 'a'
        ans = []
        r, c = 0, 0
        cnt = 0
        for ch, g in itertools.groupby(target):
            n = len(list(g))
            if ch == 'z':
                num = ord('u') - ord('a')
            else:
                num = ord(ch) - ord('a')
            new_r, new_c = num // 5, num % 5
            if new_r > r:
                ans.append('D' * (new_r - r))
            elif new_r < r:
                ans.append('U' * (r - new_r))
            if new_c > c:
                ans.append('R' * (new_c - c))
            elif new_c < c:
                ans.append('L' * (c - new_c))
            if ch == 'z':
                ans.append('D')
            ans.append('!' * n)
            r, c = (new_r, new_c) if ch != 'z' else (5, 0)
        return ''.join(ans)
