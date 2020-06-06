/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;
        vector<int> nums;
        ListNode * cur = head;
        while (cur != nullptr)
        {
            nums.push_back(cur->val);
            cur = cur->next;
        }
        return buildTree(nums, 0, nums.size() - 1);
    }
    
    TreeNode * buildTree(vector<int> & nums, int l, int r)
    {
        if(l > r) return nullptr;
        int mid = l + (r - l) / 2;
        TreeNode * root = new TreeNode(nums[mid]);
        root->left = buildTree(nums, l, mid - 1);
        root->right = buildTree(nums, mid + 1, r);
        return root;
    }
};