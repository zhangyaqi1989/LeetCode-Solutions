auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
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
class BSTIterator {
    TreeNode* cur;
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {
        cur = root;
    }
    
    /** @return the next smallest number */
    int next() {
        while (cur) {
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top();
        s.pop();
        int val = cur->val;
        cur = cur->right;
        return val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cur || (!s.empty());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
