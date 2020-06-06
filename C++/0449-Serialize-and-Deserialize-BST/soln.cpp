/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // BST
        stack<TreeNode *> stk;
        string ans = "";
        TreeNode * cur = root;
        while (!stk.empty() || cur != nullptr) {
            while (cur != nullptr) {
                ans += to_string(cur->val) + " ";
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            cur = cur->right;
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode * head = nullptr;
        stack<TreeNode *> stk;
        istringstream iss(data);
        int val;
        while (iss >> val) {
            TreeNode * node = new TreeNode(val);
            if (head == nullptr) {
                head = node;
                stk.push(node);
            } else {
                if (!stk.empty() && stk.top()->val > val) {
                    stk.top()->left = node;
                    stk.push(node);
                } else {
                    TreeNode * pre = nullptr;
                    while (!stk.empty() && stk.top()->val < val) {
                        pre = stk.top();
                        stk.pop();
                    }
                    pre->right = node;
                    stk.push(node);
                }
            }
        }
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
