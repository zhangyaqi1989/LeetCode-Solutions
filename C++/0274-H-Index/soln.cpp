class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int buckets[n + 1] = {0};
        for(int cite : citations) {
            if (cite > n) {
                ++buckets[n];
            } else {
                ++buckets[cite];
            }
        }
        int count = 0;
        for(int i = n; i >= 0; --i) {
            count += buckets[i];
            if (count >= i) return i;
        }
        return 0;
    }
};
