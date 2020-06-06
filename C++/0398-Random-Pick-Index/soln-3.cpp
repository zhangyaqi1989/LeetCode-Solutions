class Solution {
public:
    Solution(vector<int>& nums) {
        idxes_.clear();
        const int n = nums.size();
        for(int i = 0; i < n; ++i) {
            idxes_[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        const auto & lst = idxes_[target];
        const int n = lst.size();
        int r = rand() % n;
        return lst[r];
    }
    
private:
    unordered_map<int, vector<int>> idxes_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
