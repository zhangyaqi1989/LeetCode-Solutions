class Solution {
public:
    Solution(vector<int>& nums) {
        origin = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n = origin.size();
        vector<pair<int, int>> pairs;
        for(int i = 0; i < n; ++i) pairs.emplace_back(random(), origin[i]);
        sort(pairs.begin(), pairs.end());
        vector<int> ans;
        for(int i = 0; i < n; ++i) ans.push_back(pairs[i].second);
        return ans;
    }
private:
    vector<int> origin;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
