class TrieNode:
    def __init__(self):
        self.is_word = False
        self.children = collections.defaultdict(TrieNode)
        self.weight = -1

class WordFilter:

    def __init__(self, words: List[str]):
        self.pretree = TrieNode()
        self.suftree = TrieNode()
        for i, word in enumerate(words):
            self.insert(self.pretree, word, i)
            self.insert(self.suftree, word[::-1], i)
            
    def insert(self, root, word, weight):
        cur = root
        for ch in word:
            cur = cur.children[ch]
        cur.is_word = True
        cur.weight = weight
        
    def search(self, root, word):
        cur = root
        for ch in word:
            cur = cur.children.get(ch, None)
            if cur is None:
                return {-1}
        res = set()
        self.dfs(cur, res)
        return res
    
    def dfs(self, cur, res):
        if cur is not None:
            if cur.is_word:
                res.add(cur.weight)
            for ch, nei in cur.children.items():
                self.dfs(nei, res)

    def f(self, prefix: str, suffix: str) -> int:
        s1 = self.search(self.pretree, prefix)
        s2 = self.search(self.suftree, suffix[::-1])
        s = s1 & s2
        return max(s) if s else -1
        


# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(prefix,suffix)
