class TrieNode:
    def __init__(self):
        self.is_word = False
        self.children = collections.defaultdict(TrieNode)

class Solution:
    def replaceWords(self, roots, sentence):
        """
        :type roots: List[str]
        :type sentence: str
        :rtype: str
        """
        self.root = TrieNode()
        for word in roots:
            cur = self.root
            for ch in word:
                cur = cur.children[ch]
            cur.is_word = True
        words = sentence.split()
        for i, word in enumerate(words):
            cur = self.root
            for j, ch in enumerate(word):
                cur = cur.children.get(ch)
                if cur is None:
                    break
                if cur.is_word:
                    words[i] = word[:j + 1]
                    break
        return ' '.join(words)