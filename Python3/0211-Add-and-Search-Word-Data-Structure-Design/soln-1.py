class TrieNode:
    def __init__(self):
        self.is_word = False
        self.children = collections.defaultdict(TrieNode)

class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()
        

    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        cur = self.root
        for ch in word:
            cur = cur.children[ch]
        cur.is_word = True
        

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        return self.dfs(word, 0, self.root)
        
    def dfs(self, word, idx, cur):
        if idx == len(word):
            if cur and cur.is_word:
                return True
            else:
                return False
        else:
            if cur is None:
                return False
            if word[idx] == '.':
                for nxt in cur.children.values():
                    if self.dfs(word, idx + 1, nxt):
                        return True
                return False
            else:
                if self.dfs(word, idx + 1, cur.children.get(word[idx], None)):
                    return True
                else:
                    return False
        
        


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
