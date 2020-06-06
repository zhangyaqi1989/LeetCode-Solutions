class TrieNode:
    def __init__(self):
        self.val = 0
        self.children = collections.defaultdict(TrieNode)

class MapSum:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()
        

    def insert(self, key: str, val: int) -> None:
        cur = self.root
        for ch in key:
            cur = cur.children[ch]
        cur.val = val
        

    def sum(self, prefix: str) -> int:
        cur = self.root
        for ch in prefix:
            cur = cur.children.get(ch)
            if cur is None:
                return 0
        frontier = [cur]
        ans = 0
        while frontier:
            node = frontier.pop()
            ans += node.val
            for _, nei in node.children.items():
                frontier.append(nei)
        return ans


# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)
