class TrieNode:
    def __init__(self):
        self.is_word = False
        self.children = collections.defaultdict(TrieNode)
    
class StreamChecker:

    def __init__(self, words: List[str]):
        self.n = 0
        self.root = TrieNode()
        for word in words:
            self.n = max(len(word), self.n)
            cur = self.root
            for ch in word[::-1]:
                cur = cur.children[ch]
            cur.is_word = True
        self.stream = collections.deque([], self.n)

    def query(self, letter: str) -> bool:
        self.stream.append(letter)
        cur = self.root
        for i in range(len(self.stream) - 1, -1, -1):
            ch = self.stream[i]
            cur = cur.children.get(ch, None)
            if cur is None:
                return False
            else:
                if cur.is_word == True:
                    return True
        return False
        


# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)
