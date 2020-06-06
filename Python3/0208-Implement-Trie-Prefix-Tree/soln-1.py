class TrieNode():
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.is_word = False
    

class Trie(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()
        

    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: void
        """
        cur = self.root
        for ch in word:
            cur = cur.children[ch]
        cur.is_word = True
        
        
    def find(self, word):
        cur = self.root
        for ch in word:
            cur = cur.children.get(ch)
            if cur is None:
                return None
        return cur
        

    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        cur = self.find(word)
        return cur != None and cur.is_word
        

    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        cur = self.find(prefix)
        return cur != None
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)