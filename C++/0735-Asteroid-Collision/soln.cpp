class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(int item : asteroids) {
            if (ans.empty() || item > 0) {
                ans.push_back(item);
            } else {
                while (!ans.empty() && ans.back() > 0 && -item > ans.back()) {
                    ans.pop_back();
                }
                if (!ans.empty() && -item == ans.back()) ans.pop_back();
                else if (ans.empty() || ans.back() < 0)
                    ans.push_back(item);
            }
        }
        return ans;
    }
};
