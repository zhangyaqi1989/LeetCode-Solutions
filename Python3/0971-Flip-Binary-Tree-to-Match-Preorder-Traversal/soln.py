# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def flipMatchVoyage(self, root, voyage):
        """
        :type root: TreeNode
        :type voyage: List[int]
        :rtype: List[int]
        """
        parents = {}
        def traverse(node):
            if node:
                if node.left:
                    parents[node.left] = node
                    traverse(node.left)
                if node.right:
                    parents[node.right] = node
                    traverse(node.right)
        traverse(root)
        i = 0
        ans = []
        cur = root
        stack = []
        while cur or stack:
            while cur:
                if i < len(voyage):
                    if cur.val == voyage[i]:
                        stack.append(cur)
                    else:
                        if cur in parents and parents[cur].left and parents[cur].right:
                            sib = parents[cur].right if parents[cur].left == cur else parents[cur].left
                            if sib.val != voyage[i]:
                                return [-1]
                            else:
                                ans.append(parents[cur].val)
                                # cur.val, sib.val = sib.val, cur.val
                                parents[cur].left, parents[cur].right = parents[cur].right, parents[cur].left
                                cur = sib
                                stack.append(cur)
                        else:
                            return [-1]
                else:
                    return [-1]
                cur = cur.left
                i += 1
            cur = stack.pop()
            cur = cur.right
        return ans if i == len(voyage) else [-1]
