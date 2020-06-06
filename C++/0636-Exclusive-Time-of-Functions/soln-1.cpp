class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int, int>> stk;
        vector<int> ans(n, 0);
        for(string log : logs) {
            int i = log.find(':'), j = log.rfind(':');
            int idx = stoi(log.substr(0, i));
            string s = log.substr(i + 1, j - i - 1);
            int time = stoi(log.substr(j + 1));
            if (s == "start") {
                if (!stk.empty()) {
                    ans[stk.top().first] += time - stk.top().second;
                }
                stk.push({idx, time});
            } else {
                ans[stk.top().first] += time - stk.top().second + 1;
                stk.pop();
                if (!stk.empty()) stk.top().second = time + 1;
            }
        }
        return ans;
    }
};
