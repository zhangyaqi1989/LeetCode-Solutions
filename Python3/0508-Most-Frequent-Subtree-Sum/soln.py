# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findFrequentTreeSum(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        # most frequent subtree sum
        if not root: return []
        counter = collections.Counter()
        def traverse(node):
            if not node:
                return 0
            else:
                l, r = traverse(node.left), traverse(node.right)
                ans = l + r + node.val
                counter[ans] += 1
                return ans
        traverse(root)
        max_fre = counter.most_common(1)[0][1]
        ans = []
        for key, cnt in counter.most_common():
            if cnt == max_fre:
                ans.append(key)
            else:
                break
        return ans