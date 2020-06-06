class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> last_idxes(26, -1);
        const int n = S.length();
        for(int i = 0; i < n; ++i) last_idxes[S[i] - 'a'] = i;
        int r = 0;
        int l = 0;
        vector<int> sizes;
        for(int i = 0; i < n; ++i) {
            r = max(r, last_idxes[S[i] - 'a']);
            if (r == i) {
                sizes.push_back(r - l + 1);
                l = i + 1;
                r = i + 1;
            }
        }
        return sizes;
    }
};
