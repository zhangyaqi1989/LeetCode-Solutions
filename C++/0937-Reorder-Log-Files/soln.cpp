class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<tuple<string, string, int>> letters;
        vector<int> digits;
        int n = logs.size();
        for(int i = 0; i < n; ++i) {
            string log = logs[i];
            int idx = log.find(' ');
            string ident = log.substr(0, idx), rest = log.substr(idx + 1);
            if (isdigit(rest[0])) digits.push_back(i);
            else letters.emplace_back(rest, ident, i);
        }
        sort(letters.begin(), letters.end());
        vector<string> ans;
        for(auto & p : letters) ans.push_back(logs[get<2>(p)]);
        for(int idx : digits) ans.push_back(logs[idx]);
        return ans;
    }
};
