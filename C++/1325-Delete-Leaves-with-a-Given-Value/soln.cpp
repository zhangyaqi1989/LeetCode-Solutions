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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        bool delete_root = PostOrder(root, target, nullptr, true);
        return delete_root ? nullptr : root;
    }
    
private:
    // true means not exist or deleted
    bool PostOrder(TreeNode * node, int target, TreeNode * parent, bool is_left) {
        if (node != nullptr) {
            bool ld = PostOrder(node->left, target, node, true);
            bool rd = PostOrder(node->right, target, node, false);
            if (ld && rd && node->val == target) {
                if (parent != nullptr) {
                    if (is_left) parent->left = nullptr;
                    else parent->right = nullptr;
                }
                return true;
            }
            return false;
            
        }
        return true;
    }
};
