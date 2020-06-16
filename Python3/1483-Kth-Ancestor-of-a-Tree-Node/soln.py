class TreeAncestor:

    def __init__(self, n: int, parent: List[int]):
        self.height = int(math.log2(n)) + 1
        self.table = [[-1] * (self.height + 1) for _ in range(n)]
        for node, parent in enumerate(parent):
            if node > 0:
                self.table[node][0] = parent
                for i in range(1, self.height + 1):
                    self.table[node][i] = self.table[self.table[node][i - 1]][i - 1]
                    if self.table[node][i] == -1:
                        break
        

    def getKthAncestor(self, node: int, k: int) -> int:
        for i in range(self.height + 1):
            if k & (1 << i):
                node = self.table[node][i]
                if node == -1:
                    break
        return node
        


# Your TreeAncestor object will be instantiated and called as such:
# obj = TreeAncestor(n, parent)
# param_1 = obj.getKthAncestor(node,k)
