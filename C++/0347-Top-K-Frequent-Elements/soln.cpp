class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(auto num : nums) ++m[num];
        vector<int> ans;
        int n = m.size();
        priority_queue<pair<int, int>> pq; 
        for(auto & p : m) {
            int cnt = p.second, val = p.first;
            pq.push({cnt, val});
            if (pq.size() > n - k) {
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ans;
    }
};
