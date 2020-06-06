# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class CBTInserter:

    def __init__(self, root: TreeNode):
        queue = collections.deque([root])
        self.slots = [None]
        while queue:
            node = queue.popleft()
            self.slots.append(node)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        self.nxt = len(self.slots)
            
        

    def insert(self, v: int) -> int:
        parent = self.slots[self.nxt // 2]
        node = TreeNode(v)
        if self.nxt & 1:
            parent.right = node
        else:
            parent.left = node
        self.nxt += 1
        self.slots.append(node)
        return parent.val

    def get_root(self) -> TreeNode:
        return self.slots[1]
        


# Your CBTInserter object will be instantiated and called as such:
# obj = CBTInserter(root)
# param_1 = obj.insert(v)
# param_2 = obj.get_root()
