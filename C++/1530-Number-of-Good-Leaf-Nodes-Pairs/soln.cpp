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
    int countPairs(TreeNode* root, int distance) {
        int cnt = 0;
        Postorder(root, distance, &cnt);
        return cnt;
    }
    
private:
    vector<int> Postorder(TreeNode * node, int distance, int * cnt) {
        vector<int> counter(11, 0);
        if(node == nullptr) return counter;
        auto left = Postorder(node->left, distance, cnt);
        auto right = Postorder(node->right, distance, cnt);
        if(node->left == nullptr && node->right == nullptr) {
            ++counter[0];
            return counter;
        }
        for(int i = 1; i < distance; ++i) {
            for(int j = 1; j + i <= distance; ++j) {
                *cnt += left[i - 1] * right[j - 1];
            }
        }
        for(int i = 0; i < distance; ++i) {
            counter[i + 1] += left[i] + right[i];
        }
        return counter;
    }
};
