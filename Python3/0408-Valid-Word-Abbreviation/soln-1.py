class Solution:
    def validWordAbbreviation(self, word: str, abbr: str) -> bool:
        i, n = 0, len(word)
        num = 0
        for ch in abbr:
            if ch.isdigit():
                if num == 0 and ch == '0':
                    return False
                num = num * 10 + int(ch)
            else:
                i += num
                num = 0
                if i >= n or ch != word[i]:
                    return False
                i += 1
        i += num
        return i == n
