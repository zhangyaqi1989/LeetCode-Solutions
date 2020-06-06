class Solution:
    def findDuplicateSubtrees(self, root):
        """
        :type root: TreeNode
        :rtype: List[TreeNode]
        """
        d = collections.defaultdict(list)
        def traverse(node):
            if not node: return '#'
            struct = "{}{}{}".format(str(node.val), traverse(node.left), traverse(node.right))
            d[struct].append(node)
            return struct
        traverse(root)
        return [lst[0] for struct, lst in d.items() if len(lst) > 1]