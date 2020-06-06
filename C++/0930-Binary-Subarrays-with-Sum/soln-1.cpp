class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int cnt = 0;
        int n = A.size();
        vector<int> seen(n + 1, 0);
        seen[0] = 1;
        int acc = 0;
        for(int num : A) {
            acc += num;
            if (acc - S >= 0) cnt += seen[acc - S];
            seen[acc] += 1;
        }
        return cnt;
    }
};
