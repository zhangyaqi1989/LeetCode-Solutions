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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        // pre.clear();
        // suc.clear();
        initSuc(root, target);
        initPre(root, target);
        // cout << suc.top()->val << endl;
        // cout << pre.top()->val << endl;
        if (!pre.empty() && !suc.empty() && suc.top()->val == pre.top()->val) {
            nextSuc();
        }
        vector<int> ans;
        while(k-- > 0) {
            if (pre.empty()) ans.push_back(nextSuc());
            else if (suc.empty()) ans.push_back(nextPre());
            else {
                if (abs(suc.top()->val - target) < abs(pre.top()->val - target)) {
                    ans.push_back(nextSuc());
                } else {
                    ans.push_back(nextPre());
                }
            }
        }
        return ans;
    }
    
private:
    stack<TreeNode *> pre;
    stack<TreeNode *> suc;
    void initSuc(TreeNode * root, double target) {
        while (root != nullptr) {
            if (root->val == target) {
                suc.push(root);
                break;
            } else if (root->val > target) {
                suc.push(root);
                root = root->left;
            } else {
                root = root->right;
            }
        }
    }
    
    void initPre(TreeNode * root, double target) {
        while (root != nullptr) {
            if (root->val == target) {
                pre.push(root);
                break;
            } else if (root->val < target) {
                pre.push(root);
                root = root->right;
            } else {
                root = root->left;
            }
        }
    }
    
    int nextSuc() {
        TreeNode * t = suc.top();
        suc.pop();
        int val = t->val;
        t = t->right;
        while (t != nullptr) {
            suc.push(t);
            t = t->left;
        }
        return val;
    }
    
    int nextPre() {
        TreeNode * t = pre.top();
        pre.pop();
        int val = t->val;
        t = t->left;
        while (t != nullptr) {
            pre.push(t);
            t = t->right;
        }
        return val;
    }
};
