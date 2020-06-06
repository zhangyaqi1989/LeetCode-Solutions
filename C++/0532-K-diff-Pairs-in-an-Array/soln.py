class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int cnt = 0;
        unordered_map<int, int> counter;
        for(auto num : nums) counter[num]++;
        for(auto & pair : counter) {
            int num = pair.first;
            // cout << num << " " << pair.second << endl;
            if((k == 0 && pair.second > 1) || (k != 0 && counter.find(num + k) != counter.end())) ++cnt;
        }
        return cnt;
    }
};
