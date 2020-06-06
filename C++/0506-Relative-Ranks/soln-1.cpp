class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<pair<int, int>> array;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            array.push_back(make_pair(nums[i], i));
        }
        sort(array.rbegin(), array.rend());
        vector<string> res(n, "");
        for(int i = 0; i < n; ++i) {
            auto p = array[i];
            int pos = p.second;
            if (i == 0) res[pos] = "Gold Medal";
            else if (i == 1) res[pos] = "Silver Medal";
            else if (i == 2) res[pos] = "Bronze Medal";
            else res[pos] = to_string(i + 1);
        }
        return res;
    }
};
