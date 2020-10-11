# Definition for a binary tree node.
# class Node(object):
#     def __init__(self, val=" ", left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def checkEquivalence(self, root1: 'Node', root2: 'Node') -> bool:
        def post_order(node):
            ans = collections.Counter()
            if node is None:
                return ans
            if node.left is None and node.right is None:
                ans[node.val] += 1
            else:
                l = post_order(node.left)
                r = post_order(node.right)
                for val, cnt in l.items():
                    ans[val] += cnt
                for val, cnt in r.items():
                    ans[val] += cnt
            return ans
        r1 = post_order(root1)
        r2 = post_order(root2)
        return r1 == r2
