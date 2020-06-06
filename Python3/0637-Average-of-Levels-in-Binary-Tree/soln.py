# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def averageOfLevels(self, root):
        """
        :type root: TreeNode
        :rtype: List[float]
        """
        nodes, ans = [root], []
        while nodes:
            val, cnt = 0, 0
            temp = []
            for node in nodes:
                val += node.val
                cnt += 1
                temp.extend([nei for nei in (node.left, node.right) if nei])
            ans.append(val / cnt)
            nodes = temp
        return ans