class Solution:
    def isSubtree(self, s, t):
        """
        :type s: TreeNode
        :type t: TreeNode
        :rtype: bool
        """
        if not t or not s:
            return t == s
        return self.isSame(s, t) or self.isSubtree(s.left, t) or self.isSubtree(s.right, t)
        
    def isSame(self, s, t):
        if not t or not s:
            return t == s
        return s.val == t.val and self.isSame(s.left, t.left) and self.isSame(s.right, t.right)