class TrieNode:
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.is_word = False

class WordFilter:

    def __init__(self, words):
        """
        :type words: List[str]
        """
        self.preTree = TrieNode()
        self.sucTree = TrieNode()
        for word in words:
            self.insert(self.preTree, word)
        for word in words:
            self.insert(self.sucTree, word[::-1])
        self.d = dict(zip(words, range(len(words))))
    
    def insert(self, root, word):
        cur = root
        for ch in word:
            cur = cur.children[ch]
        cur.is_word = True
    
    def search(self, root, word):
        cur = root
        for ch in word:
            cur = cur.children.get(ch)
            if cur is None:
                return []
        res = []
        self.dfs(cur, word, res)
        return res
    
    def dfs(self, cur, pre, res):
        if cur is None: return
        if cur.is_word:
            res.append(pre)
        for ch, node in cur.children.items():
            self.dfs(node, pre + ch, res)
        

    def f(self, prefix, suffix):
        """
        :type prefix: str
        :type suffix: str
        :rtype: int
        """
        pres = self.search(self.preTree, prefix)
        sucs = self.search(self.sucTree, suffix[::-1])
        sucs = [word[::-1] for word in sucs]
        cands = set(pres) & set(sucs)
        return max([self.d[cand] for cand in cands] or [-1])
        


# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(prefix,suffix)