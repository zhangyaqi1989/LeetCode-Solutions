class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> seen;
        seen.insert({0, 1});
        int cur = 0, cnt = 0;
        for(int num : A) {
            cur = (cur + num % K + K) % K;
            auto it = seen.find(cur);
            if (it != seen.end()) cnt += it->second;
            ++seen[cur];
        }
        return cnt;
    }
};
