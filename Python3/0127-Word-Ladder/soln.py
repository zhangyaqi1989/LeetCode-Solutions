class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        words = set(wordList)
        if endWord not in words:
            return 0
        s1 = {beginWord}
        s2 = {endWord}
        seen = set()
        step = 0
        while s1 and s2:
            if len(s2) < len(s1):
                s1, s2 = s2, s1
            s = set()
            step += 1
            for word in s1:
                for i in range(len(word)):
                    for ch in string.ascii_lowercase:
                        newword = word[:i] + ch + word[i + 1:]
                        if newword in s2:
                            return step + 1
                        if newword in words:
                            words.remove(newword)
                            s.add(newword)
            s1 = s
        return 0