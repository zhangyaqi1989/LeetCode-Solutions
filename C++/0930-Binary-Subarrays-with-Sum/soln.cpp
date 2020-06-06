class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int cnt = 0;
        unordered_map<int, int> seen;
        seen[0] = 1;
        int acc = 0;
        for(int num : A) {
            acc += num;
            auto it = seen.find(acc - S);
            if (it != seen.end()) cnt += it->second;
            seen[acc] += 1;
        }
        return cnt;
    }
};
