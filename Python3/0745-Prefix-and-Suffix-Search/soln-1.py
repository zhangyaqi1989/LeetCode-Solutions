class TrieNode():
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.is_word = False
        self.weight = 0
        self.word = ''

class WordFilter:

    def __init__(self, words):
        """
        :type words: List[str]
        """
        self.pre_root = TrieNode()
        self.suf_root = TrieNode()
        for i, word in enumerate(words):
            cur = self.pre_root
            for ch in word:
                cur = cur.children[ch]
            cur.is_word = True
            cur.weight = i
            cur.word = word
            cur = self.suf_root
            for ch in word[::-1]:
                cur = cur.children[ch]
            cur.is_word = True
            cur.weight = i
            cur.word = word
            
    def search(self, root, fix):
        cur = root
        for ch in fix:
            cur = cur.children.get(ch, None)
            if not cur:
                return []
        ans = []
        stack = [cur]
        while stack:
            node = stack.pop()
            if node.is_word:
                ans.append((node.word, node.weight))
            for nei in node.children:
                stack.append(node.children[nei])
        return ans

    def f(self, prefix, suffix):
        """
        :type prefix: str
        :type suffix: str
        :rtype: int
        """
        pres = self.search(self.pre_root, prefix)
        sufs = self.search(self.suf_root, suffix[::-1])
        s = set(pres) & set(sufs)
        return -1 if not s else max(pair[1] for pair in s)
        


# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(prefix,suffix)