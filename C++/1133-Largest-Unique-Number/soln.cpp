class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        int ans = -1;
        map<int, int> counter;
        for(int num : A) ++counter[num];
        for(auto it = counter.rbegin(); it != counter.rend(); ++it) {
            if(it->second == 1) return it->first;
        }
        return ans;
    }
};
