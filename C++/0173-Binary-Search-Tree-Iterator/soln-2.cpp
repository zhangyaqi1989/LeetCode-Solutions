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
public:
    BSTIterator(TreeNode* root): cur_(root) {
    }
    
    /** @return the next smallest number */
    int next() {
        while(cur_ != nullptr) {
            st_.push(cur_);
            cur_ = cur_->left;
        }
        cur_ = st_.top();
        st_.pop();
        int ans = cur_->val;
        cur_ = cur_->right;
        return ans;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st_.empty() || cur_ != nullptr;
    }
    
private:
    stack<TreeNode *> st_;
    TreeNode * cur_;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
