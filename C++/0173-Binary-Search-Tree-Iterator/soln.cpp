/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode *> s;
    TreeNode * cur;
    TreeNode * node;
public:
    BSTIterator(TreeNode *root) {
        cur = root;
        node = NULL;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (cur == NULL && s.empty())
            return false;
        while (cur != NULL)
        {
            s.push(cur);
            cur = cur -> left;
        }
        cur = s.top();
        s.pop();
        node = cur;
        cur = cur -> right;
        return true;
    }

    /** @return the next smallest number */
    int next() {
        return node->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */