class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mx = 0;
        for(int i = 30; i >= 0; --i) {
            unordered_set<int> prefixes;
            for(int num : nums) prefixes.insert(num >> i);
            mx <<= 1;
            int cand = mx + 1;
            for(auto p : prefixes) {
                if (prefixes.find(p ^ cand) != prefixes.end()) {
                    mx = cand;
                    break;
                }
            }
        }
        return mx;
    }
};
