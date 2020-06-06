class Solution:
    def minMutation(self, start: str, end: str, bank: List[str]) -> int:
        # bidirection BFS
        bank = set(bank)
        if end not in bank:
            return -1
        s1, s2 = {start}, {end}
        step = 0
        while s1 and s2:
            if s1 > s2:
                s1, s2 = s2, s1
            s = set()
            for word in s1:
                for i in range(8):
                    for ch in "ACGT":
                        new_word = word[:i] + ch + word[i + 1:]
                        if new_word in s2:
                            return step + 1
                        if new_word in bank:
                            bank.remove(new_word)
                            s.add(new_word)
            s1 = s
            step += 1
        return -1
