class TrieNode:
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.val = 0

class MapSum:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()
        

    def insert(self, key, val):
        """
        :type key: str
        :type val: int
        :rtype: void
        """
        cur = self.root
        for ch in key:
            cur = cur.children[ch]
        cur.val = val

    def sum(self, prefix):
        """
        :type prefix: str
        :rtype: int
        """
        ans = 0
        cur = self.root
        for ch in prefix:
            cur = cur.children[ch]
        stack = [cur]
        while stack:
            node = stack.pop()
            ans += node.val
            for ch in node.children:
                stack.append(node.children[ch])
        return ans
        


# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)