class TrieNode():
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.is_word = False

class Solution:
    def longestWord(self, words):
        """
        :type words: List[str]
        :rtype: str
        """
        self.root = TrieNode()
        for word in words:
            cur = self.root
            for ch in word:
                cur = cur.children[ch]
            cur.is_word = True
        for word in sorted(words, key=lambda word: (-len(word), word)):
            cur = self.root
            for ch in word:
                cur = cur.children.get(ch)
                if cur is None or not cur.is_word:
                    break
            else:
                return word
        return ""