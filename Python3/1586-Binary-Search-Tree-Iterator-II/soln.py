# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:

    def __init__(self, root: TreeNode):
        self._vals = []
        self._idx = 0
        self._stack = []
        self._cur = root
        

    def hasNext(self) -> bool:
        if self._idx < len(self._vals):
            return True
        return self._stack or self._cur is not None

    def next(self) -> int:
        if self._idx < len(self._vals):
            ans = self._vals[self._idx]
            self._idx += 1
            return ans
        while self._cur is not None:
            self._stack.append(self._cur)
            self._cur = self._cur.left
        top = self._stack.pop()
        self._cur = top.right
        ans = top.val
        self._vals.append(ans)
        self._idx += 1
        return ans

    def hasPrev(self) -> bool:
        idx = self._idx - 2
        return idx >= 0 and idx < len(self._vals)        

    def prev(self) -> int:
        ans = self._vals[self._idx - 2]
        self._idx -= 1
        return ans
        


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.hasNext()
# param_2 = obj.next()
# param_3 = obj.hasPrev()
# param_4 = obj.prev()
