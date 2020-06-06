class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> dnums;
        for(int num : nums) dnums.push_back((double) num);
        return dfs(dnums);
    }
    
private:
    bool dfs(vector<double> nums) {
        if ((int) nums.size() == 1) {
            if (abs(nums[0] - 24.0) < 0.000001) return true;
            else return false;
        }
        sort(nums.begin(), nums.end());
        int total = 1;
        for(int i = 2; i <= (int) nums.size(); ++i) total *= i;
        while (total-- > 0) {
            double a = nums[0], b = nums[1];
            vector<double> temp = {a + b};
            temp.insert(temp.end(), nums.begin() + 2, nums.end());
            if (dfs(temp)) return true;
            temp.clear();
            temp.push_back(a - b);
            temp.insert(temp.end(), nums.begin() + 2, nums.end());
            if (dfs(temp)) return true;
            temp.clear();
            temp.push_back(a * b);
            temp.insert(temp.end(), nums.begin() + 2, nums.end());
            if (dfs(temp)) return true;  
            if (b != 0) {
                temp.clear();
                temp.push_back(a / b);
                temp.insert(temp.end(), nums.begin() + 2, nums.end());
                if (dfs(temp)) return true;                
            }
            next_permutation(nums.begin(), nums.end());
        }
        return false;
    }
};
