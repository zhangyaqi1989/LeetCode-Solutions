class Solution:
    def isSubtree(self, s, t):
        """
        :type s: TreeNode
        :type t: TreeNode
        :rtype: bool
        """
        def encode(node):
            return '^' + str(node.val) + encode(node.left) + encode(node.right) if node else '$'
        return encode(t) in encode(s)