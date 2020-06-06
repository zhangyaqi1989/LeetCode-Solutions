struct Record {
    int id;
    int start;
    int recursive_time;
};

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<Record> records;
        vector<int> times(n, 0);
        for(const string & log : logs) {
            int i = log.find(':');
            int j = log.rfind(':');
            string op = log.substr(i + 1, j - i - 1);
            int id = stoi(log.substr(0, i));
            int t = stoi(log.substr(j + 1));
            if (op == "start") {
                records.push({id, t, 0});
            } else {
                auto record = records.top();
                records.pop();
                int dt = t - record.start + 1;
                times[record.id] += dt - record.recursive_time;
                if (!records.empty()) {
                    records.top().recursive_time += dt;
                }
            }
        }
        return times;
    }
};
