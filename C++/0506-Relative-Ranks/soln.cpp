class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        priority_queue<pair<int, int>> pq;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            pq.push(make_pair(nums[i], i));
        }
        vector<string> res(n, "");
        for(int i = 0; i < n; ++i) {
            auto p = pq.top();
            pq.pop();
            int pos = p.second;
            if (i == 0) res[pos] = "Gold Medal";
            else if (i == 1) res[pos] = "Silver Medal";
            else if (i == 2) res[pos] = "Bronze Medal";
            else res[pos] = to_string(i + 1);
        }
        return res;
    }
};
