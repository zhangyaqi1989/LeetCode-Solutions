# use trie
class TrieNode:
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.is_word = False
        self.times = 0
        
class AutocompleteSystem:

    def __init__(self, sentences, times):
        """
        :type sentences: List[str]
        :type times: List[int]
        """
        self.root = TrieNode()
        for sentence, time in zip(sentences, times):
            self.insert(sentence, time)
        self.cur = self.root
        self.search = ''
    
    def insert(self, sentence, time):
        cur = self.root
        for ch in sentence:
            cur = cur.children[ch]
        cur.is_word = True
        cur.times += time
        

    def input(self, c):
        """
        :type c: str
        :rtype: List[str]
        """
        if c == '#':
            self.insert(self.search, 1)
            self.search = ''
            self.cur = self.root
            return []
        else:
            self.search += c
            if not self.cur: return []
            self.cur = self.cur.children.get(c)
            pairs = self.traverse(self.cur)
            pairs.sort(key=lambda x : (-x[1], x[0]))
            ans = [sentence for sentence, time in pairs]
            return ans if len(ans) <= 3 else ans[:3]
            
    def traverse(self, ptr):
        if not ptr: return []
        stack = [(ptr, self.search)]
        ans = []
        while stack:
            node, string = stack.pop()
            if node.is_word:
                ans.append((string, node.times))
            for nei in node.children:
                stack.append((node.children[nei], string + nei))
        return ans
        


# Your AutocompleteSystem object will be instantiated and called as such:
# obj = AutocompleteSystem(sentences, times)
# param_1 = obj.input(c)