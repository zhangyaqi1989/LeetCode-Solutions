class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return helper(A, K) - helper(A, K + 1);
    }
    
    int helper(vector<int>& A, int K) {
        int ans = 0;
        int j = 0;
        map<int, int> counter;
        for(auto num : A) {
            counter[num]++;
            while(counter.size() >= K) {
                counter[A[j]]--;
                if(counter[A[j]] == 0)
                    counter.erase(A[j]);
                ++j;
            }
            ans += j;
        }
        return ans;
    }
};
