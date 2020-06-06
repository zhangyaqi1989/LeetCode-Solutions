class Solution {
public:
    string rankTeams(vector<string>& votes) {
        const int kM = votes[0].size();
        vector<vector<int>> ranks(26, vector<int>(kM, 0));
        for(string vote : votes) {
            for(int idx = 0; idx < kM; ++idx) {
                ++ranks[vote[idx] - 'A'][idx];
            }
        }
        sort(votes[0].begin(), votes[0].end(), [&](char a, char b) {
            for(int i = 0; i < kM; ++i) {
                if(ranks[a - 'A'][i] != ranks[b - 'A'][i])
                    return ranks[a - 'A'][i] > ranks[b - 'A'][i];
            }
            return a < b;
        });
        return votes[0];
    }
};
