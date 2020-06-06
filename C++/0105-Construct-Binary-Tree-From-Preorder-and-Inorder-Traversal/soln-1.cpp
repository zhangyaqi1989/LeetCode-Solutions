/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return Build(preorder, inorder, 0, n - 1, 0, n - 1);
        
    }

private:
    TreeNode * Build(const vector<int> & preorder, const vector<int> & inorder, 
                    int lo_pre, int hi_pre, int lo_in, int hi_in) {
        if(lo_pre > hi_pre) return nullptr;
        TreeNode * root = new TreeNode(preorder[lo_pre]);
        int idx = lo_in;
        while(idx <= hi_in) {
            if(inorder[idx] == preorder[lo_pre]) break;
            ++idx;
        }
        // idx - lo_in;
        root->left = Build(preorder, inorder, lo_pre + 1, lo_pre + idx - lo_in, lo_in, idx - 1);
        root->right = Build(preorder, inorder, lo_pre + idx - lo_in + 1, hi_pre, idx + 1, hi_in);
        return root;
    }
    
};
