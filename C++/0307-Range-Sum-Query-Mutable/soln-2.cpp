class SegmentTreeNode {
public:
    int start;
    int end;
    int val;
    SegmentTreeNode * left;
    SegmentTreeNode * right;
    
    SegmentTreeNode(int start, int end, int val, 
                    SegmentTreeNode* left = nullptr, SegmentTreeNode* right=nullptr):
                    start(start), end(end), val(val), left(left), right(right) {};
    SegmentTreeNode(const SegmentTreeNode & other) = delete;
    SegmentTreeNode & operator=(const SegmentTreeNode & other) = delete;
    ~SegmentTreeNode() {
        if (left != nullptr) {
            delete left;
            left = nullptr;
        }
        if (right != nullptr) {
            delete right;
            right = nullptr;
        }
    }
    
};
class NumArray {
public:
    NumArray(vector<int>& nums) {
        if (nums.empty()) return;
        nums_ = nums;
        root_.reset(buildTree(0, (int) nums.size() - 1));
        // cout << "finish build\n";
    }
    
    void update(int i, int val) {
        return update(root_.get(), i, val);
    }
    
    int sumRange(int i, int j) {
        return sumRange(root_.get(), i, j);
    }

private:
    SegmentTreeNode * buildTree(int start, int end) {
        if (start == end) {
            return new SegmentTreeNode(start, end, nums_[start]);
        }
        int mid = start + (end - start) / 2;
        SegmentTreeNode * left = buildTree(start, mid);
        SegmentTreeNode * right = buildTree(mid + 1, end);
        return new SegmentTreeNode(start, end, left->val + right->val, left, right);
    }
    
    void update(SegmentTreeNode * root, int idx, int val) {
        if (root->start == idx && root->end == idx) {
            root->val = val;
            return;
        }
        int mid = root->start + (root->end - root->start) / 2;
        if (idx <= mid) {
            update(root->left, idx, val);
        } else {
            update(root->right, idx, val);
        }
        root->val = root->left->val + root->right->val;
    }
    
    int sumRange(SegmentTreeNode * root, int start, int end) {
        if (root->start == start && root->end == end) {
            return root->val;
        }
        int mid = root->start + (root->end - root->start) / 2;
        if (start > mid) {
            return sumRange(root->right, start, end);
        } else if (end <= mid) {
            return sumRange(root->left, start, end);
        } else {
            return sumRange(root->left, start, mid) + sumRange(root->right, mid + 1, end);
        }
    }

    vector<int> nums_;
    unique_ptr<SegmentTreeNode> root_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
