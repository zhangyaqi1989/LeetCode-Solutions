class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0, mx_ndoubles = 0;
        for(int num : nums) {
            int ndoubles = 0;
            while(num) {
                if(num % 2 == 1) {
                    ++ans;
                    --num;
                } else {
                    ++ndoubles;
                    num /= 2;
                }
            }
            mx_ndoubles = max(mx_ndoubles, ndoubles);
        }
        return ans + mx_ndoubles;
    }
};
