# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        nums = []
        cur = head
        while cur:
            nums.append(cur.val)
            cur = cur.next
        def build(i, j):
            if j - i <= 0:
                return None
            mid = (i + j - 1) // 2
            root = TreeNode(nums[mid])
            root.left, root.right = build(i, mid), build(mid + 1, j)
            return root
        return build(0, len(nums))