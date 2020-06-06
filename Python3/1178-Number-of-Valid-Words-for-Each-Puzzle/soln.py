class Solution:
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        counter = collections.Counter()
        for w in words:
            if len(set(w)) > 7:
                continue
            code = 0
            for ch in w:
                code |= (1 << (ord(ch) - 97))
            counter[code] += 1
        ans = []
        for p in puzzles:
            code = (1 << (ord(p[0]) - 97))
            total = (1 << 6)
            cnt = 0
            for i in range(total):
                c = code
                for j in range(6):
                    if (i & (1 << j)):
                        c |= (1 << (ord(p[j + 1]) - 97))
                cnt += counter[c]
            ans.append(cnt)
        return ans
