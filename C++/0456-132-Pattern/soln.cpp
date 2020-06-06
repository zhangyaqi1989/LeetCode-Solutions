auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int a3 = INT_MIN;
        int n = nums.size();
        for(int i = n - 1; i >= 0; --i) {
            if (nums[i] < a3) return true;
            while(!s.empty() && nums[i] > s.top()) {
                a3 = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};
