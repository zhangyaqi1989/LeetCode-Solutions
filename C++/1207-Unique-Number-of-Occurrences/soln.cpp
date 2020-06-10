class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        const int kN = 2005;
        vector<int> counter(kN, 0);
        for(int num : arr) ++counter[num + 1000];
        bitset<1001> seen;
        for(int i = 0; i < kN; ++i) {
            if(!counter[i]) continue;
            if(seen[counter[i]]) return false;
            seen[counter[i]] = 1;
        }
        return true;
    }
};
