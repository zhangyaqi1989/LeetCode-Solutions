class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        unordered_map<string, int> needed;
        for(int i = 0; i < n; ++i) needed[req_skills[i]] = i;
        vector<vector<int>> dp;
        dp.resize(1 << n);
        vector<int> init;
        int m = people.size();
        for(int i = 0; i < m; ++i) init.push_back(i);
        for(int i = 0; i < (1 << n); ++i) {
            dp[i] = init;
        }
        dp[0].clear();
        for(int i = 0; i < m; ++i) {
            int skill = 0;
            for(string str : people[i]) {
                auto it = needed.find(str);
                if (it != needed.end()) skill |= (1 << it->second);
            }
            for(int j = 0; j < (1 << n); ++j) {
                int new_skill = j | skill;
                if ((new_skill) == j) continue;
                if (dp[new_skill].size() > dp[j].size() + 1) {
                    dp[new_skill] = dp[j];
                    dp[new_skill].push_back(i);
                }
            }
        }
        return dp.back();
    }
};
