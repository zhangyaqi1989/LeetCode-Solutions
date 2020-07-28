class TrieNode:
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.val = -1

class FileSystem:

    def __init__(self):
        self.root = TrieNode()

    def createPath(self, path: str, value: int) -> bool:
        cur = self.root
        dirs = path.split('/')[1:]
        for d in dirs[:-1]:
            cur = cur.children.get(d, None)
            if cur is None:
                return False
        name = dirs[-1]
        if name in cur.children:
            return False
        cur.children[name].val = value
        return True
            

    def get(self, path: str) -> int:
        dirs = path.split('/')[1:]
        cur = self.root
        for d in dirs:
            cur = cur.children.get(d, None)
            if cur is None:
                return -1
        return cur.val


# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.createPath(path,value)
# param_2 = obj.get(path)
