/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        tree.push_back(nullptr);
        queue<TreeNode *> frontier;
        frontier.push(root);
        while (!frontier.empty()) {
            TreeNode * node = frontier.front();
            frontier.pop();
            tree.push_back(node);
            if (node->left) frontier.push(node->left);
            if (node->right) frontier.push(node->right);
        }
        nxt = tree.size();
    }
    
    int insert(int v) {
        TreeNode * node = new TreeNode(v);
        TreeNode * parent = tree[nxt / 2];
        if (nxt & 1) {
            parent->right = node;
        } else {
            parent->left = node;
        }
        tree.push_back(node);
        ++nxt;
        return parent->val;
    }
    
    TreeNode* get_root() {
        return tree[1];
    }
private:
    vector<TreeNode *> tree;
    int nxt;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
