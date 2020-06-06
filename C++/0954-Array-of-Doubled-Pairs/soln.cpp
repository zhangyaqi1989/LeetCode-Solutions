class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        vector<int> poss, negs;
        for(int num : A) {
            if (num >= 0) poss.push_back(num);
            else negs.push_back(-num);
        }
        return helper(poss) && helper(negs);
    }
    
    bool helper(vector<int> & nums) {
        int n = nums.size();
        if (n % 2 == 1) return false;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> counter;
        for(int num : nums) ++counter[num];
        for(int num : nums) {
            if (counter[num] > 0) {
                if (counter[2 * num] > 0) {
                    --counter[num];
                    --counter[2 * num];
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
