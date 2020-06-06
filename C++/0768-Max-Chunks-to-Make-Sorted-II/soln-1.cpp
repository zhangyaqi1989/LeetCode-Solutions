class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        const int n = arr.size();
        vector<int> idxes(n);
        iota(idxes.begin(), idxes.end(), 0);
        sort(idxes.begin(), idxes.end(), [&](int i, int j) 
             {return arr[i] == arr[j] ? i < j : arr[i] < arr[j];});
        int cnt = 0;
        int r = -1;
        for(int i = 0; i < n; ++i) {
            r = max(r, idxes[i]);
            if (i == r) ++cnt;
        }
        return cnt;
    }
};
