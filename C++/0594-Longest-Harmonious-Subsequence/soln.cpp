class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> counter;
        for(int num : nums) ++counter[num];
        int ans = 0;
        for(auto & p : counter) {
            int a = p.first;
            if (counter.find(a + 1) != counter.end()) {
                ans = max(ans, counter[a + 1] + p.second);
            }
        }
        return ans;
    }
};
