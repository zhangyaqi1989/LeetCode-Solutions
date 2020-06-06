class TrieNode:
    def __init__(self):
        self.isin = False
        self.children = collections.defaultdict(TrieNode)

class StreamChecker:

    def __init__(self, words: List[str]):
        self.checker = TrieNode()
        for word in words:
            ptr = self.checker
            for ch in reversed(word):
                ptr = ptr.children[ch]
            ptr.isin = True
        self.stream = []
        

    def query(self, letter: str) -> bool:
        self.stream.append(letter)
        ptr = self.checker
        for ch in reversed(self.stream):
            ptr = ptr.children.get(ch, None)
            if ptr is None:
                return False
            if ptr.isin:
                return True
        return False


# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)

