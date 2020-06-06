class Node:
    __slots__ = ['val', 'levels']
    def __init__(self, val, n):
        self.val = val
        self.levels = [None] * n

class Skiplist:

    def __init__(self):
        self.head = Node(-1, 16)
        
    def _iter(self, target):
        cur = self.head
        for level in range(15, -1, -1):
            while True:
                nxt = cur.levels[level]
                if nxt and nxt.val < target:
                    cur = nxt
                else:
                    break
            yield cur, level

    def search(self, target: int) -> bool:
        for cur, level in self._iter(target):
            pass
        return cur.levels[0] is not None and cur.levels[0].val == target
            
        
    def add(self, num: int) -> None:
        node_levels = min(16, 1 + int(math.log2(1.0 / (random.random()))))
        node = Node(num, node_levels)
        for cur, level in self._iter(num):
            if level < node_levels:
                nxt = cur.levels[level]
                cur.levels[level] = node
                node.levels[level] = nxt
        

    def erase(self, num: int) -> bool:
        ans = False
        for cur, level in self._iter(num):
            nxt = cur.levels[level]
            if nxt is not None and nxt.val == num:
                ans = True
                cur.levels[level] = nxt.levels[level]
        return ans

# Your Skiplist object will be instantiated and called as such:
# obj = Skiplist()
# param_1 = obj.search(target)
# obj.add(num)
# param_3 = obj.erase(num)
