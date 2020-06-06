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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int, int> sums;
        postorder(root, sums);
        vector<int> ans;
        int mx = 0;
        for(auto & p : sums) {
            if (p.second > mx) {
                ans.clear();
                ans.push_back(p.first);
                mx = p.second;
            } else if (p.second == mx) {
                ans.push_back(p.first);
            }
        }
        return ans;
    }
    
    int postorder(TreeNode * node, map<int, int> & sums) {
        if (node != nullptr) {
            int left = postorder(node->left, sums);
            int right = postorder(node->right, sums);
            int ans = node->val + left + right;
            ++sums[ans];
            return ans;
        } else {
            return 0;
        }
    }
};
