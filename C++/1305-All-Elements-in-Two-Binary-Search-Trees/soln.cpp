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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> vals1, vals2;
        Inorder(root1, &vals1);
        Inorder(root2, &vals2);
        int i = 0, j = 0;
        vector<int> ans;
        const int kN1 = vals1.size(), kN2 = vals2.size();
        while (i < kN1 && j < kN2) {
            if (vals1[i] < vals2[j]) {
                ans.push_back(vals1[i++]);
            } else {
                ans.push_back(vals2[j++]);
            }
        }
        while (i < kN1) ans.push_back(vals1[i++]);
        while (j < kN2) ans.push_back(vals2[j++]);
        return ans;
    }
    
private:
    void Inorder(TreeNode * node, vector<int> * vals) {
        if (node != nullptr) {
            Inorder(node->left, vals);
            vals->push_back(node->val);
            Inorder(node->right, vals);
        }
    }
};
