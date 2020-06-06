class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        words = set(wordList)
        if endWord not in words:
            return 0
        s1, s2 = {beginWord}, {endWord}
        step = 1
        while s1 and s2:
            if len(s1) > len(s2):
                s1, s2 = s2, s1
            s = set()
            step += 1
            for word in s1:
                for i in range(len(word)):
                    for ch in string.ascii_lowercase:
                        new_word = word[:i] + ch + word[i + 1:]
                        if new_word in s2:
                            return step
                        if new_word in words:
                            s.add(new_word)
                            words.remove(new_word)
            s1 = s
        return 0
