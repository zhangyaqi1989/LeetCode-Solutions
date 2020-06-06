class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        map<string, int> counter;
        istringstream iss (A + " " + B);
        string s;
        while (iss >> s) {
            ++counter[s];
        }
        vector<string> ans;
        for(auto & p : counter) {
            if (p.second == 1)
                ans.push_back(p.first);
        }
        return ans;
    }
};
