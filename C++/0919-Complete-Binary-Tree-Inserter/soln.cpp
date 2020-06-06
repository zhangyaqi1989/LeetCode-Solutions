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
    vector<TreeNode*> tree;
    int cnt = 0;
public:
    CBTInserter(TreeNode* root) {
        tree.push_back(nullptr);
        tree.push_back(root);
        for(int i = 1; i < tree.size(); ++i) {
            if(tree[i]->left) tree.push_back(tree[i]->left);
            if(tree[i]->right) tree.push_back(tree[i]->right);
        }
        cnt = tree.size() - 1;
        // cout << cnt << endl;
    }
    
    int insert(int v) {
        int idx = cnt + 1;
        int parent_idx = idx / 2;
        TreeNode* node = new TreeNode(v);
        // cout << node->val << endl;
        tree.push_back(node);
        if (idx & 1 == 1) tree[parent_idx]->right = node;
        else tree[parent_idx]->left = node;
        cnt += 1;
        return tree[parent_idx]->val;
    }
    
    TreeNode* get_root() {
        return tree[1];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
