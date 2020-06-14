class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> groups(50, 0);
        for(int num = 1; num <= n; ++num) {
            int val = num;
            int digit_sum = 0;
            while(val) {
                digit_sum += val % 10;
                val /= 10;
            }
            ++groups[digit_sum];
        }
        int mx = *max_element(groups.begin(), groups.end());
        return count(groups.begin(), groups.end(), mx);
    }
};
