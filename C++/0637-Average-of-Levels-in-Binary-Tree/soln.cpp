static const auto ______ = []() {
    std::cout.sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if (root == NULL) return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            double sum = 0;
            int cnt = 0;
            for(int i = 0; i < size; ++i)
            {
                TreeNode * node = q.front();
                q.pop();
                sum += node -> val;
                cnt++;
                if (node -> left != nullptr) q.push(node->left);
                if (node -> right != nullptr) q.push(node->right);
            }
            ans.push_back(sum/cnt);
        }
        return ans;
    }
};