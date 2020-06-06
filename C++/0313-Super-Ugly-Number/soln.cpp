class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> idxes(primes.size(), 0);
        vector<int> nums = {1};
        while (nums.size() < n)
        {
            int end = nums[nums.size() - 1];
            vector<int> nexts;
            for(auto i = 0; i < primes.size(); ++i)
            {
                while (primes[i] * nums[idxes[i]] <= end) ++idxes[i];
                nexts.push_back(primes[i] * nums[idxes[i]]);
            }
            nums.push_back(*min_element(nexts.begin(), nexts.end()));
        }
        return nums[n - 1];
    }
};