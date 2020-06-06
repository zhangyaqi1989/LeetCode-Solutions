class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        const int n = req_skills.size();
        vector<int> skills;
        for(const auto & p : people) {
            int mask = 0;
            for(const string & s : p) {
                mask |= 1 << (find(req_skills.begin(), req_skills.end(), s) - req_skills.begin());
            }
            skills.push_back(mask);
        }
        
        const int target = (1 << n)  - 1;
        vector<int> dp(1 << n, INT_MAX / 2);
        unordered_map<int, pair<int, int>> parents;
        dp[0] = 0;
        for (int i = 0; i < people.size(); ++i) {
            const int k = skills[i];
            for (int j = target; j >= 0; --j) {
                if (dp[j] + 1 < dp[j | k]) {
                    dp[j | k] = dp[j] + 1;
                    parents[j | k] = {j, i};
                }
            }
        }
        // cout << dp[target] << endl;
        vector<int> ans;
        int t = target;
        while (t) {
            const auto & parent = parents[t];
            ans.push_back(parent.second);
            t = parent.first;
        }
        return ans;
    }
};
