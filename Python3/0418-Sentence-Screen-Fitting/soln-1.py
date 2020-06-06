class Solution:
    def wordsTyping(self, sentence: List[str], rows: int, cols: int) -> int:
        if any(len(word) > cols for word in sentence):
            return 0
        lens = [len(word) for word in sentence]
        cur = cnt = 0
        row = col = 0
        total = sum(lens) + len(lens)
        while True:
            if col == 0:
                cnt += cols // total
                col += cols // total * total
            if col + lens[cur] <= cols:
                col += lens[cur] + 1
                cur += 1
                if cur >= len(sentence):
                    cnt += 1
                    cur %= len(sentence)
            else:
                col = 0
                row += 1
                if cur == 0:
                    left = rows - row
                    cnt += (left // row) * cnt
                    rows = left % row
                    row = 0
                if row == rows:
                    return cnt
        return cnt
