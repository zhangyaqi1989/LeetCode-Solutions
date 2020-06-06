class TrieNode:
    def __init__(self):
        self.is_word = False
        self.children = collections.defaultdict(TrieNode)

class Solution:
    def replaceWords(self, roots: List[str], sentence: str) -> str:
        tree = TrieNode()
        for word in roots:
            cur = tree
            for ch in word:
                cur = cur.children[ch]
            cur.is_word = True
        tokens = sentence.split()
        for i, token in enumerate(tokens):
            cur = tree
            for j, ch in enumerate(token, 1):
                cur = cur.children[ch]
                if cur.is_word:
                    tokens[i] = token[:j]
                    break
        return ' '.join(tokens)
