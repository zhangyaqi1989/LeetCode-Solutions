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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        return check(root) && isValidBST(root->left) && isValidBST(root->right);
    }
    
private:
    bool check(TreeNode * root) {
        TreeNode * pre = root->left;
        if (pre != nullptr) {
            while (pre->right != nullptr) pre = pre->right;
            if (pre->val >= root->val) return false;
        }
        TreeNode * suc = root->right;
        if (suc != nullptr) {
            while (suc->left != nullptr) suc = suc->left;
            if (suc->val <= root->val) return false;
        }
        return true;
        
    }
};
