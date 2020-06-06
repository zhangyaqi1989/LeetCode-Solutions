struct Record {
    int idx;
    int acc;
    int start;
    int dummy;
};

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<Record> s;
        for (string log : logs) {
            istringstream iss(log);
            string token;
            int idx, time;
            string op;
            getline(iss, token, ':');
            idx = stoi(token);
            getline(iss, op, ':');
            getline(iss, token, ':');
            time = stoi(token);
            if (op == "start") {
                if (!s.empty()) {
                    s.top().acc += time - s.top().start;
                }
                s.push({idx, 0, time});
            } else {
                // cout << s.size() << endl;
                ans[s.top().idx] += s.top().acc + time - s.top().start + 1;
                s.pop();
                if (!s.empty()) s.top().start = time + 1;
            }
        }
        return ans;
    }
};
