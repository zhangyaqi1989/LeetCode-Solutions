class Solution {
public:
    int getKth(int lo, int hi, int k) {
        unordered_map<int, int> memo;
        vector<int> nums;
        vector<int> powers;
        for(int i = lo; i <= hi; ++i) {
            nums.push_back(i);
            powers.push_back(ComputePower(i, &memo));
        }
        sort(nums.begin(), nums.end(), [&](int a, int b) 
             {return powers[a - lo] == powers[b - lo] ? a < b : powers[a - lo] < powers[b - lo];});
        return nums[k - 1];
    }
private:
    int ComputePower(int num, unordered_map<int, int> * memo) {
        auto it = memo->find(num);
        if(it != memo->end()) return it->second;
        if (num == 1) return 0;
        int result = 1;
        if (num % 2 == 0) {
            result += ComputePower(num / 2, memo);
        } else {
            result += ComputePower(num * 3 + 1, memo);
        }
        memo->insert({num, result});
        return result;
    }
};
