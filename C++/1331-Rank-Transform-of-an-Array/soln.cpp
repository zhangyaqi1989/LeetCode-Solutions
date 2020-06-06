class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> nums(arr.begin(), arr.end());
        unordered_map<int, int> idxes;
        int idx = 1;
        for(const auto & num : nums) {
            idxes[num] = idx++;
        }
        vector<int> ans;
        for(int num : arr) {
            ans.push_back(idxes[num]);
        }
        return ans;
    }
};
