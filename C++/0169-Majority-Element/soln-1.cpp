class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // majorities
        int majority = 0;
        int cnt = 0;
        for(int num : nums) {
            if(cnt == 0) {
                majority = num;
                cnt = 1;
            } else {
                if(num != majority) --cnt;
                else ++cnt;
            }
        }
        return majority;
    }
};
