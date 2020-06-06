class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> ans;
        for(int left = 1; left < bound; left *= x) {
            for(int right = 1; left + right <= bound; right *= y) {
                ans.push_back(left + right);
                if (y == 1) break;
            }
            if (x == 1) break;
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};
