class Solution:
    def minimumDistance(self, word: str) -> int:
        keyboard = [None] * 256
        ncols = 6
        word = [ord(ch) for ch in word]
        for ch in string.ascii_uppercase:
            idx = ord(ch) - ord('A')
            r, c = idx // ncols, idx % ncols
            keyboard[ord(ch)] = (r, c)
        def dist(ch1, ch2):
            r1, c1 = keyboard[ch1]
            r2, c2 = keyboard[ch2]
            return abs(r1 - r2) + abs(c1 - c2)
        memo = {}
        def dfs(cur, f1, f2):
            if cur == len(word):
                return 0
            if (cur, f1, f2) in memo:
                return memo[cur, f1, f2]
            else:
                ch = word[cur]
                ans = min(dist(ch, f1) + dfs(cur + 1, ch, f2), dist(ch, f2) + dfs(cur + 1, f1, ch))
                memo[cur, f1, f2] = ans
            return ans
        mn = math.inf
        for c1 in string.ascii_uppercase:
            for c2 in string.ascii_uppercase:
                f1, f2 = ord(c1), ord(c2)
                mn = min(mn, dfs(0, f1, f2))
        return mn
