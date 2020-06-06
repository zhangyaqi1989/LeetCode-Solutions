// SegmentTree
class SegmentTreeNode {
public:
    int start;
    int end;
    int val;
    SegmentTreeNode * left;
    SegmentTreeNode * right;
    SegmentTreeNode(int start, int end, int val, SegmentTreeNode * left, SegmentTreeNode * right):
    start(start), end(end), val(val), left(left), right(right) {}
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
        n_ = nums.size();
        root_.reset(BuildTree(0, n_ - 1));
    }
    
    void update(int i, int val) {
        Update(root_.get(), i, val);
    }
    
    int sumRange(int i, int j) {
        return Sum(root_.get(), i, j);
    }
    
private:
    SegmentTreeNode * BuildTree(int start, int end) {
        if (start == end) {
            return new SegmentTreeNode(start, end, nums_[start], nullptr, nullptr);
        }
        int mid = start + (end - start) / 2;
        SegmentTreeNode * root = new SegmentTreeNode(start, end, 0, nullptr, nullptr);
        SegmentTreeNode * left = BuildTree(start, mid);
        SegmentTreeNode * right = BuildTree(mid + 1, end);
        root->val = left->val + right->val;
        root->left = left;
        root->right = right;
        return root;
    }
    
    void Update(SegmentTreeNode * root, int idx, int val) {
        if (root->start == idx && root->end == idx) {
            root->val = val;
            return;
        }
        int mid = root->start + (root->end - root->start) / 2;
        if (idx <= mid) {
            Update(root->left, idx, val);
        } else {
            Update(root->right, idx, val);
        }
        root->val = root->left->val + root->right->val;
    }
    
    int Sum(SegmentTreeNode * root, int start, int end) {
        if (root->start == start && root->end == end) {
            return root->val;
        }
        int mid = root->start + (root->end - root->start) / 2;
        if (end <= mid) {
            return Sum(root->left, start, end);
        } else if (start > mid) {
            return Sum(root->right, start, end);
        } else {
            return Sum(root->left, start, mid) + Sum(root->right, mid + 1, end);
        }
    }
    
    vector<int> nums_;
    int n_;
    unique_ptr<SegmentTreeNode> root_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
